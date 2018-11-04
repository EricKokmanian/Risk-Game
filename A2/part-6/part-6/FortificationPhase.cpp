#include <iostream>
#include "FortificationPhase.h"

using namespace std;

FortificationPhase::FortificationPhase() {

}

FortificationPhase::FortificationPhase(Player* player) {
	this->player = player;
}

void FortificationPhase::moveArmy() {
	selectFromCountry();
	selectToCountry();
}

void FortificationPhase::selectFromCountry() {
	cout << "Please enter the corresponding number of the country you want to move armies from: " << endl;
	int i = 1;
	for (auto it = player->getCountries().begin(); it != player->getCountries().end(); ++it) {
		cout << i << ". " << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
		i++;
	}
	while(true){

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
}

void FortificationPhase::selectToCountry() {
	cout << "Please enter the corresponding number of the country you want to move armies to: " << endl;
	int i = 1;
	for (auto it = fromCountry->getAdjacentCountries().begin(); it != fromCountry->getAdjacentCountries().end(); ++it) {
		cout << i << ". " << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
		i++;
	}
	int playerChoice = 0;
	cin >> playerChoice;
	toCountry = fromCountry->getAdjacentCountries()[playerChoice - 1];
	cout << "You are moving armies from " << fromCountry->getCountryName() << " to " << toCountry->getCountryName() << endl;
}