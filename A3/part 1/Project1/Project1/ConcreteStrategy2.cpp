#include "ConcreteStrategy2.h"
#include "FortificationPhase.h"
#include "AttackPhase.h"
#include <vector>

using namespace std;

// Class that will adopt the PASSIVE PLAYER STRATEGY
ConcreteStrategy2::ConcreteStrategy2() {

}

void ConcreteStrategy2::reinforce(Map worldmap, Player* player) {
	int x = worldmap.getNumberOfCountries(*player);
	
	if (x < 3) {
		x = 3;
	}
	//x += player->ifOwnContinent(); ???

	string name;
	cout << "NUMBER OF COUNTRIES BY " << player->getName() << " : " << x << endl;
	cout << "Here are the countries owned by David :" << player->getCountries(1) << endl << "You have " << x << " armies to place." << endl;
	for (int a = 0; a < x; a++) {
		// Check country with least armies
		vector <Country*> countries = player->getCountries();

		int minArmy = countries.at(0)->getArmyNumber(); // temporary setting minimum nbr of armies for player's countries
		Country* minArmies = NULL; // player's country with the least amount of armies

		for (auto it = countries.begin(); it != countries.end(); it++) {
			if ((*it)->getArmyNumber() < minArmy) {
				minArmy = (*it)->getArmyNumber();
				minArmies = (*it);
			}
		}

		cout << minArmies->getCountryName() << " has just been reinforced with 1 army since it was your weakest country." << endl;
		minArmies->addArmy(1);
		cout << "NUMBER OF ARMIES OF " << worldmap.getCountry(minArmies->getCountryName())->getCountryName() << " : " << worldmap.getCountry(minArmies->getCountryName())->getArmyNumber() << endl;
	}

	cout << "-------- END OF REINFORCEMENT PHASE ---------" << endl;
}

void ConcreteStrategy2::attack(Player* player) {
	cout << player->getName() << " (passive) decided to not attack..." << endl;
	cout << "-------- END OF ATTACK PHASE ---------" << endl;
}

void ConcreteStrategy2::fortify(Player* player) {
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
		
		/*Select From Country*/
		cout << "Now moving armies from your strongest country to your weakest (passive)..." << endl;
		vector <Country*> countries = player->getCountries();
		max = countries.at(0)->getArmyNumber();
		int i = 1;

		for (auto it = countries.begin(); it != countries.end(); ++it) {
			/*cout << i << ". " << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
			i++;*/
			if ((*it)->getArmyNumber > max) {
				max = (*it)->getArmyNumber();
				strongest = (*it);
			}
		}

		while (true) {

			/*int playerChoice = 0;
			cin >> playerChoice;*/
			fromCountry = strongest;
			if (fromCountry->getArmyNumber() < 2) {
				cout << "Please choose a country where there is an army of 2 or more." << endl;
			}
			else {
				cout << "You're gonna move armies from " << fromCountry->getCountryName() << endl;
				break;
			}
		}

		/*Select To Country*/
		cout << "Please enter the corresponding number of the country you want to move armies to: " << endl;
		int j = 1;
		min = countries.at(0)->getArmyNumber();

		for (auto it = fromCountry->getAdjacentCountries().begin(); it != fromCountry->getAdjacentCountries().end(); ++it) {
			/*cout << j << ". " << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
			j++;*/
			if ((*it)->getArmyNumber() < min) {
				min = (*it)->getArmyNumber();
				weakest = (*it);
			}
		}

		/*int playerChoice = 0;
		cin >> playerChoice;*/
		toCountry = weakest;
		cout << "You are moving armies from " << fromCountry->getCountryName() << " (strongest country) to " << toCountry->getCountryName() << " (weakest country)." << endl;

		/*Select army size*/
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
				cout << fromCountry->getCountryName() << " has now " << fromCountry->getArmyNumber() << endl;
				cout << toCountry->getCountryName() << " has now " << toCountry->getArmyNumber() << endl;
				break;
			}
		}
	}

}