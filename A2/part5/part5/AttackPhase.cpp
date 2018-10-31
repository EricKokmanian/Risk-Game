#include <iostream>
#include <string>
#include "AttackPhase.h"

using namespace std;

AttackPhase::AttackPhase() {

}

void AttackPhase::setPlayer(Player* player) {
	this->player = player;
}

// starts and ends the attack phase
void AttackPhase::attack() {
	bool keepAttacking = true;
	while (keepAttacking) {
		int i = 1;
		cout << "Please enter the corresponding number of the country you want to attack with: " << endl;
		for (auto it = player->getCountries().begin(); it != player->getCountries().end(); ++it) {
			cout << i << ". " << (*it)->getCountryName() << endl;
			i++;
		}
		chooseCountry();
		break;
	}
}

// player selects country to attack 
void AttackPhase::chooseCountry() {
	int playerChoice = 0;
	cin >> playerChoice;
	attackingCountry = player->getCountries()[playerChoice - 1];
	cout << "You're gonna attack with " << attackingCountry->getCountryName() << endl;
	cout << "Enter the corresponding number of the country you want to attack: " << endl;

	int i = 1;
	for (auto it = attackingCountry->getAdjacentCountries().begin(); it != attackingCountry->getAdjacentCountries().end(); ++it) {
		if ((*it)->getOwner() != player) {
			cout << i << ". " << (*it)->getCountryName() << endl;
			i++;
		}
		
	}
}

// setup the dices to be rolled
void AttackPhase::chooseDice() {

}

// dices are rolled and change army values
void AttackPhase::rollingDice() {

}