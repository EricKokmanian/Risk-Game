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
	Country* fromCountry;
	Country* toCountry;

	cout << "Do you want to move an army from a country to another?" << endl;
	string playerChoice = "";
	cin >> playerChoice;

	if (playerChoice == "yes") {
		
		/*Select From Country*/
		cout << "Please enter the corresponding number of the country you want to move armies from: " << endl;
		int i = 1;
		for (auto it = player->getCountries().begin(); it != player->getCountries().end(); ++it) {
			cout << i << ". " << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
			i++;
		}
		while (true) {

			int playerChoice = 0;
			cin >> playerChoice;
			fromCountry = player->getCountries()[playerChoice - 1];
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
		for (auto it = fromCountry->getAdjacentCountries().begin(); it != fromCountry->getAdjacentCountries().end(); ++it) {
			cout << j << ". " << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
			j++;
		}
		int playerChoice = 0;
		cin >> playerChoice;
		toCountry = fromCountry->getAdjacentCountries()[playerChoice - 1];
		cout << "You are moving armies from " << fromCountry->getCountryName() << " to " << toCountry->getCountryName() << endl;

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