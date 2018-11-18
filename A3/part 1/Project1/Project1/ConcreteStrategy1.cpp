#include "ConcreteStrategy1.h"
#include "FortificationPhase.h"
#include "AttackPhase.h"
#include <vector>

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
		string playerAnswer = "";
		bool keppAttacking = true;

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
				else {
					cout << "(else)" << endl;
					maxArmies = countries.at(0);
				}
			}
			//player selects attacking country
			attackingCountry = maxArmies;
			cout << "An Attack will be launched from " << attackingCountry << " that has an army of " << attackingCountry->getArmyNumber() << " (aggressive)" << endl;
			//search for enemy countries surrounding the elected attacking country
			vector<Country*> defendingCountries;
			for (auto it = attackingCountry->getAdjacentCountries().begin(); it != attackingCountry->getAdjacentCountries().end(); ++it) {
				if ((*it)->getOwner() != player) {
					defendingCountries.push_back((*it));
				}
			}

			//if not enough army size
			if (attackingCountry->getArmyNumber() < 2) {
				cout << "You can only attack with a country of 2 or more armies." << endl;
			}

			//if there are no defending countries
			else if (defendingCountries.size() == 0) {
				cout << "There are no enemy countries surrounding " << attackingCountry->getCountryName() << endl;
			}
			else {
				//attacker chooses which country to attack
				attack1.chooseCountry();
				//attacker and defender choose the number of dices to roll
				attack1.chooseDice();
				//game rolls the dices and declares the winner and reduces army sizes accordingly
				attack1.rollingDice();
				//if defending country has 0 army, ownership is transfered to the attacker and can move his army
				attack1.isConquered();

			}
			if (attackingCountry->getArmyNumber() < 2)
			{
				cout << " You have no more armies left to attack on your strongest country " << attackingCountry << " attacking phase will end." << endl;
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
				else {
					cout << "(else)" << endl;
					strongest = countries.at(0);
				}
			}


			toCountry = strongest;

			int j = 1;
			min = 100;
			for (auto it = countries.begin(); it != countries.end(); it++) {
				if ((*it) != strongest && (*it)->getArmyNumber() <= min ) {
					min = (*it)->getArmyNumber();
					weakest = (*it);
				}
				else {
					//if ((*it) != strongest)
					weakest = countries.at(1);
				}

				
				while (true) {
					string choice;
					fromCountry = weakest;
					if (fromCountry->getArmyNumber() < 2) {
						cout << "Please choose a country where there is an army of 2 or more." << endl;
						cin >> choice;
					}
					else {
						cout << "You're going to move armies from " << fromCountry->getCountryName() << endl;
						break;
					}
				}

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
		}
	
	

