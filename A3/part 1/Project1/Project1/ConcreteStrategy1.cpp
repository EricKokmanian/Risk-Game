#include "ConcreteStrategy1.h"
#include "FortificationPhase.h"
#include "AttackPhase.h"
#include <vector>
#include <algorithm>
using namespace std;

// Class that will adopt the AGGRESSIVE PLAYER STRATEGY
ConcreteStrategy1::ConcreteStrategy1() {

}

void ConcreteStrategy1::reinforce(Map worldmap, Player* player) {
	int x = worldmap.getNumberOfCountries(*player);
	if (x < 3) {
		x = 3;
	}

	string name;
	cout << "\nNUMBER OF COUNTRIES BY " << player->getName() << " : " << x << endl;
	cout << "Here are the countries owned by " << player->getName() << " : " << player->getCountries(1) << endl << "You have " << x << " armies to place." << endl;
	for (int i = 0; i < x; i++) {
		//check country with most armies

		vector <Country*> countries = player->getCountries();

		int maxArmy = 1; // temporary setting minimum number of armies for player's countries

		Country* maxArmies = NULL; // player's country with the least amount of armies;

		for (auto it = countries.begin(); it != countries.end(); it++) {
			if ((*it)->getArmyNumber() >= maxArmy) {
				maxArmy = (*it)->getArmyNumber();
				maxArmies = (*it);
			}
			else {
				cout << "(else)" << endl;
				maxArmies = countries.at(0);
			}
		}

		cout << maxArmies->getCountryName() << " has just been reinforced with 1 army since it was your strongest country." << endl;
		maxArmies->addArmy(1);
		cout << "NUMBER OF ARMIES OF " << worldmap.getCountry(maxArmies->getCountryName())->getCountryName() << " : " << worldmap.getCountry(maxArmies->getCountryName())->getArmyNumber() << endl;

		cout << "       -------- END OF REINFORCEMENT PHASE ---------\n" << endl;
	}
}
	void ConcreteStrategy1::attack(Player* player) {
		int playerChoice = 0;
		bool keppAttacking = true;
		int attackArmySize;
		int defendArmySize;
		int numAttackDices;
		int numDefenseDices;
		int attackerLost;
		int defenderLost;
		string attackerName;
		string defenderName;
		AttackPhase attack1;

		attack1.setPlayer(player);

		vector <Country*> countries = player->getCountries();

		int maxArmy = 1;
		Country* maxArmies = NULL;

		while (keppAttacking) {
			int counter = 1;
			Country* fromCountry = NULL;
			Country* strongest = NULL; // country with most armies

			int max = 0; // nbr of armies in the strongest country
			
			for (auto it = countries.begin(); it != countries.end(); it++) {
				if ((*it)->getArmyNumber() >= maxArmy) {
					maxArmy = (*it)->getArmyNumber();
					maxArmies = (*it);
				}
			}
			//player selects attacking country
		
			cout << "An Attack will be launched from " << maxArmies->getCountryName() << " that has an army of " << maxArmies->getArmyNumber() << " (aggressive)" << endl;
			//search for enemy countries surrounding the elected attacking country
			vector<Country*> defendingCountries;
			for (auto it = maxArmies->getAdjacentCountries().begin(); it != maxArmies->getAdjacentCountries().end(); ++it) {
				if ((*it)->getOwner() != player) {
					defendingCountries.push_back((*it));
				}
			}

			//if not enough army size
			if (maxArmies->getArmyNumber() < 2) {
				cout << "You can only attack with a country of 2 or more armies." << endl;
			}

			//if there are no defending countries
			else if (defendingCountries.size() == 0) {
				cout << "There are no enemy countries surrounding " << maxArmies->getCountryName() << endl;
			}
			else {
				//attacker chooses which country to attack
				//attack1.chooseCountry();
				cout << "Enter the corrsponding number of the country you want to attack: " << endl;
				int i = 1;
				vector<Country*> defendingCountries;
				// list all the countries that the attacker can attack
				for (auto it = maxArmies->getAdjacentCountries().begin(); it != maxArmies->getAdjacentCountries().end(); ++it) {
					if ((*it)->getOwner() != player) {
						defendingCountries.push_back((*it));
						cout << i << ". " << (*it)->getCountryName() << endl;
						i++;
					}
				}
				// attacker has chosen which country to attack, initialize variables
				cin >> playerChoice;
				defendingCountry = defendingCountries[playerChoice - 1 ];
				defender = defendingCountry->getOwner();
				attackArmySize = maxArmies->getArmyNumber();
				defendArmySize = defendingCountry->getArmyNumber();
				attackerName = player->getName();
				defenderName = defendingCountry->getOwner()->getName();

				//attacker and defender choose the number of dices to roll
				cout << "============" << maxArmies->getCountryName() << " OWNED BY " << attackerName << " IS ATTACKING "
					<< defendingCountry->getCountryName() << " OWNED BY " << defenderName << "============" << endl;
				cout << "Attacker: " << maxArmies->getCountryName() << " has an army of " << attackArmySize << endl;
				cout << "Defender: " << defendingCountry->getCountryName() << " has an army of " << defendArmySize << endl;

				if (attackArmySize == 2) {
					cout << attackerName << ", you can only attack with 1 dice" << endl;
					numAttackDices = 1;
					system("pause");
				}
				else {
					cout << " Attacking with full force! (Aggressive) " << endl;
					if (attackArmySize >= 4)
						numAttackDices = 3;
					numAttackDices = 2;
				}
				

				if (defendArmySize == 1) {
					cout << defenderName << ", you can only defend with 1 dice" << endl;
					numDefenseDices = 1;
					system("pause");
				}
				else {
					cout << defenderName << ", you can defend with 1 or 2 dices\n How many dices do you want to use?" << endl;
					cin >> numDefenseDices;
				}
				//game rolls the dices and declares the winner and reduces army sizes accordingly
				vector<int> attackDiceValues;
				vector<int> defenseDiceValues;
				attackerLost = 0;
				defenderLost = 0;

				// roll dices for both parties
				attackDiceValues = player->getDice()->roll(numAttackDices);
				defenseDiceValues = defender->getDice()->roll(numDefenseDices);
				// sort the results in descending order
				sort(attackDiceValues.rbegin(), attackDiceValues.rend());
				sort(defenseDiceValues.rbegin(), defenseDiceValues.rend());

				cout << "\nThe attacker rolled : ";
				for (auto it = attackDiceValues.begin(); it != attackDiceValues.end(); ++it) {
					cout << (*it) << " ";
				}

				cout << "\nThe defender rolled : ";
				for (auto it = defenseDiceValues.begin(); it != defenseDiceValues.end(); ++it) {
					cout << (*it) << " ";
				}
				// set the number of comparisons of dices
				int compareCount = min(attackDiceValues.size(), defenseDiceValues.size());
				// compare the dice values and count the army losses for each party
				for (int i = 0; i < compareCount; i++) {
					if (attackDiceValues[i] > defenseDiceValues[i]) {
						defenderLost++;
					}
					else {
						attackerLost++;
					}
				}
				cout << "\nAttacker lost an army of " << attackerLost << endl;
				cout << "Defender lost an army of " << defenderLost << endl;
				// update the army values of the countries
				maxArmies->setArmyNumber(attackArmySize - attackerLost);
				defendingCountry->setArmyNumber(defendArmySize - defenderLost);

				cout << "\nAttacker: " << maxArmies->getCountryName() << " has " << maxArmies->getArmyNumber() << " armies left." << endl;
				cout << "Defender: " << defendingCountry->getCountryName() << " has " << defendingCountry->getArmyNumber() << " armies left." << endl;

				//if defending country has 0 army, ownership is transfered to the attacker and can move his army
				if (defendingCountry->getArmyNumber() == 0) {
					// transfer ownership of country
					defendingCountry->setOwner(player);
					// set the army size of newly conquered country to remaining attacking army
					defendingCountry->setArmyNumber(numAttackDices - attackerLost);
					maxArmies->setArmyNumber(attackArmySize - defendingCountry->getArmyNumber());
					defender->removeCountry(defendingCountry);
					player->addCountry(defendingCountry);
					defendingCountry->setOwner(player);
					cout << defenderName << " has lost " << defendingCountry->getCountryName() << endl;
					cout << attackerName << " has conquered " << defendingCountry->getCountryName() << endl;

					// move army after conquering defending country
					cout << attackerName << ", do you want to move your army from " << maxArmies->getCountryName()
						<< " to " << defendingCountry->getCountryName() << "?" << endl;
					string playerChoice;
					cin >> playerChoice;
					if (playerChoice == "yes") {
						cout << maxArmies->getCountryName() << " has an army of " << maxArmies->getArmyNumber()
							<< " and " << defendingCountry->getCountryName() << " has an army of " << defendingCountry->getArmyNumber() << endl;
						cout << "How many armies do you want to move to " << defendingCountry->getCountryName() << "?" << endl;
						while (true) {
							int armySize = 0;
							cin >> armySize;
							if (armySize >= maxArmies->getArmyNumber()) {
								cout << "You need to keep at least one army on " << maxArmies->getCountryName() << endl;
							}
							else {
								int attackArmy = maxArmies->getArmyNumber();
								int defendArmy = defendingCountry->getArmyNumber();
								maxArmies->setArmyNumber(attackArmy - armySize);
								defendingCountry->setArmyNumber(defendArmy + armySize);
								cout << maxArmies->getCountryName() << " has now " << maxArmies->getArmyNumber() << endl;
								cout << defendingCountry->getCountryName() << " has now " << defendingCountry->getArmyNumber() << endl;
								break;
							}
						}

					}
					else {
						return;
					}
				}
			}

			if (maxArmies->getArmyNumber() < 2 || defendingCountries.size() == 0)
			{
				cout << " You have no more armies left to attack on your strongest country " << maxArmies << " attacking phase will end." << endl;
				keppAttacking = false;
			}
		}	
	}

	void  ConcreteStrategy1::fortify(Player* player) {

		Country* fromCountry = NULL;
		Country* strongest = NULL; // country with most armies
		int max = 0; // nbr of armies in strongest country
		Country* weakest = NULL; // country with the least armies
		int min = 0; // nbr of armies in weakest country
		Country* toCountry = NULL;
		cout << "FORTIFICATION PHASE HAS STARTED!" << endl;
		cout << "Do you want to move an army from a country to another?" << endl;
		string playerChoice = "";
		cin >> playerChoice;

		if (playerChoice == "yes") {
			vector <Country*> countries = player->getCountries();

			cout << "\nNow, here are your countries and their corresponding number of armies: " << endl;
			for (auto it = countries.begin(); it != countries.end(); it++) {
				cout << " - " << (*it)->getCountryName() << " has now " << (*it)->getArmyNumber() << " armies." << endl;
			}
			cout << endl;

			// Select from country
			cout << "Now moving armies from your weakest country to your strongest (aggressive)...." << endl;

			max = countries.at(0)->getArmyNumber();
			int i = 1;

			for (auto it = countries.begin(); it != countries.end(); it++) {
				if ((*it)->getArmyNumber() >= max) {
					max = (*it)->getArmyNumber();
					strongest = (*it);
				}
			}


			toCountry = strongest;

			int j = 1;
			min = 100;
			for (auto it = countries.begin(); it != countries.end(); it++) {
				if ((*it) != strongest && (*it)->getArmyNumber() <= min && (*it)->getArmyNumber() > 1) {
					min = (*it)->getArmyNumber();
					weakest = (*it);
				}

				}

				
				
					string choice;
					fromCountry = weakest;

					
						cout << "You're going to move armies from " << fromCountry->getCountryName() << endl;
						
					
				

				cout << " You are moving armies from " << fromCountry->getCountryName() << " (weakest country) to " << toCountry->getCountryName() << " (strongest country)." << endl;

				// select army size

				cout << "How many armies do you want to move?" << endl;

				while (true) {
					int playerChoice = 0;
					cin >> playerChoice;
					if (playerChoice >= fromCountry->getArmyNumber()) {
						cout << "Please keep at least one army left on " << fromCountry->getCountryName() << endl;
					}
					else {
						int fromCountrySize = fromCountry->getArmyNumber();
						int toCountrySize = toCountry->getArmyNumber();
						fromCountry->setArmyNumber(fromCountrySize - playerChoice);
						toCountry->setArmyNumber(toCountrySize + playerChoice);
						cout << fromCountry->getCountryName() << " has now " << fromCountry->getArmyNumber() << " armies." << endl;
						cout << toCountry->getCountryName() << " has now " << toCountry->getArmyNumber() << " armies." << endl;
						break;
					}
				}

			}

		}
		
	
	

