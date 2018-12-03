#include "ConcreteStrategy2.h"
#include "FortificationPhase.h"
#include "AttackPhase.h"
#include <vector>

using namespace std;

// Class that will adopt the PASSIVE PLAYER STRATEGY
ConcreteStrategy2::ConcreteStrategy2() {

}

void ConcreteStrategy2::reinforce(Map* worldmap, Player* player) {
	int x = worldmap->getNumberOfCountries(*player);

	if (x < 3) {
		x = 3;
	}
	//x += player->ifOwnContinent(); ???

	string name;
	cout << "\nNUMBER OF COUNTRIES BY " << player->getName() << " : " << x << endl;
	cout << "Here are the countries owned by " << player->getName() << " :" << player->getCountries(1) << endl << "You have " << x << " armies to place." << endl;
	for (int a = 0; a < x; a++) {
		// Check country with least armies
		vector <Country*> countries = player->getCountries();

		int minArmy = 100; // temporary setting minimum nbr of armies for player's countries

		Country* minArmies = NULL; // player's country with the least amount of armies

		for (auto it = countries.begin(); it != countries.end(); it++) {
			if ((*it)->getArmyNumber() <= minArmy) {
				minArmy = (*it)->getArmyNumber();
				minArmies = (*it);
			}
			else {
				/*cout << "(else)" << endl;
				minArmies = countries.at(0);*/
			}
		}

		cout << minArmies->getCountryName() << " has just been reinforced with 1 army since it was your weakest country." << endl;
		minArmies->addArmy(1);
		cout << "NUMBER OF ARMIES OF " << worldmap->getCountry(minArmies->getCountryName())->getCountryName() << " : " << worldmap->getCountry(minArmies->getCountryName())->getArmyNumber() << endl;
	}

	cout << "       -------- END OF REINFORCEMENT PHASE ---------\n" << endl;
}

void ConcreteStrategy2::attack(Player* player) {
	cout << player->getName() << " (passive) decided to not attack..." << endl;
	cout << "       --------    END OF ATTACK PHASE     ---------\n" << endl;
}

void ConcreteStrategy2::fortify(Player* player) {
	Country* fromCountry = NULL;
	Country* strongest = NULL; // country with most armies
	int max = 0; // nbr of armies in strongest country
	Country* weakest = NULL; // country with the least armies
	int min = 0; // nbr of armies in weakest country
	Country* toCountry = NULL;
	string playerChoice = "";
	if (tournament == false) {
		cout << "Do you want to move an army from a country to another?" << endl;
		cin >> playerChoice;
	}
	playerChoice = "yes";
	if (playerChoice == "yes") {
		vector <Country*> countries = player->getCountries();

		cout << "\nNow, here are your countries and their corresponding number of armies: " << endl;
		for (auto it = countries.begin(); it != countries.end(); ++it) {
			cout << " - " << (*it)->getCountryName() << " has now " << (*it)->getArmyNumber() << " armies." << endl;
		}
		cout << endl;

		/*Select From Country*/
		cout << "Now moving armies from your strongest country to your weakest (passive)..." << endl;

		max = countries.at(0)->getArmyNumber();

		int i = 1;

		for (auto it = countries.begin(); it != countries.end(); ++it) {
			if ((*it)->getArmyNumber() >= max) {
				max = (*it)->getArmyNumber();
				strongest = (*it);
			}
			else {
				/*cout << "(else)" << endl;
				strongest = countries.at(0);*/
			}
		}

		fromCountry = strongest;

		if (fromCountry->getArmyNumber() < 2) {
			cout << "Please choose a country where there is an army of 2 or more." << endl;
		}
		else
			cout << "You're gonna move armies from " << fromCountry->getCountryName() << endl;

		/*Select To Country*/
		int j = 1;
		min = 100;

		// b4: auto it = fromCountry->getAdjacentCountries().begin(); it != fromCountry->getAdjacentCountries().end(); ++it
		for (auto it = countries.begin(); it != countries.end(); ++it) {
			if ((*it)->getArmyNumber() <= min) {
				min = (*it)->getArmyNumber();
				weakest = (*it);
			}
			//else
			//weakest = countries.at(0);
		}

		toCountry = weakest;
		cout << "You are moving armies from " << fromCountry->getCountryName() << " (strongest country) to " << toCountry->getCountryName() << " (weakest country)." << endl;

		/*Select army size*/
		if (tournament == false) {
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
		else {
			if (fromCountry->getArmyNumber() > 1) {
				cout << " Moving 1 army " << endl;
				fromCountry->setArmyNumber(fromCountry->getArmyNumber() - 1);
				toCountry->setArmyNumber(toCountry->getArmyNumber() + 1);
				cout << fromCountry->getCountryName() << " has now " << fromCountry->getArmyNumber() << " armies." << endl;
				cout << toCountry->getCountryName() << " has now " << toCountry->getArmyNumber() << " armies." << endl;
			}else
			cout << " Not enough armies to move anywhere!" << endl;

		}
	}

}
