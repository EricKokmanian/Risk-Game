#include <iostream>
#include <algorithm>
#include <string>
#include "AttackPhase.h"

using namespace std;

AttackPhase::AttackPhase() {
	numAttackDices = 0;
	numDefenseDices = 0;
	attackerLost = 0;
	defenderLost = 0;
}

void AttackPhase::setPlayer(Player* player) {
	this->attacker = player;
}

// starts and ends the attack phase
void AttackPhase::attack() {
	bool keepAttacking = true;
	string playerAnswer = "";
	while (keepAttacking) {
		int i = 1;
		cout << "Please enter the corresponding number of the country you want to attack with: " << endl;
		for (auto it = attacker->getCountries().begin(); it != attacker->getCountries().end(); ++it) {
			if ((*it)->getArmyNumber() > 1) {
				cout << i << ". " << (*it)->getCountryName() << endl;
				i++;
			}
		}
		chooseCountry();
		chooseDice();
		rollingDice();
		isConquered();
		cout << attacker->getName() << ", do you want to keep attacking?" << endl;
		cin >> playerAnswer;
		if (playerAnswer == "no") {
			keepAttacking = false;
		}
	}
}

// player selects country to attack 
void AttackPhase::chooseCountry() {
	int playerChoice = 0;
	cin >> playerChoice;
	attackingCountry = attacker->getCountries()[playerChoice - 1];
	cout << "You're gonna attack with " << attackingCountry->getCountryName() << endl;
	cout << "Enter the corresponding number of the country you want to attack: " << endl;

	int i = 1;
	vector<Country*> defendingCountries;
	for (auto it = attackingCountry->getAdjacentCountries().begin(); it != attackingCountry->getAdjacentCountries().end(); ++it) {
		if ((*it)->getOwner() != attacker) {
			defendingCountries.push_back((*it));
			cout << i << ". " << (*it)->getCountryName() << endl;
			i++;
		}
	}
	cin >> playerChoice;
	defendingCountry = defendingCountries[playerChoice - 1];
	defender = defendingCountry->getOwner();
	attackArmySize = attackingCountry->getArmyNumber();
	defendArmySize = defendingCountry->getArmyNumber();
	attackerName = attacker->getName();
	defenderName = defender->getName();
}

// setup the dices to be rolled
void AttackPhase::chooseDice() {

	cout << "============" << attackingCountry->getCountryName() << " OWNED BY " << attackerName << " IS ATTACKING "
		<< defendingCountry->getCountryName() << " OWNED BY " << defenderName << "============" << endl;
	cout << "Attacker: " << attackingCountry->getCountryName() << " has an army of " << attackArmySize << endl;
	cout << "Defender: " << defendingCountry->getCountryName() << " has an army of " << defendArmySize << endl;

	if (attackArmySize == 2) {
		cout << attackerName << ", you can only attack with 1 dice" << endl;
		numAttackDices = 1;
		system("pause");
	}
	else if (attackArmySize == 3) {
		cout << attackerName << ", you can attack with 1 or 2 dices\n How many dices do you want to use?" << endl;
		cin >> numAttackDices;
	}
	else {
		cout << attackerName << ", you can attack with 1, 2 or 3 dices\n How many dices do you want to use?" << endl;
		cin >> numAttackDices;
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
}

// dices are rolled and change army values
void AttackPhase::rollingDice() {
	vector<int> attackDiceValues;
	vector<int> defenseDiceValues;

	attackDiceValues = attacker->getDice()->roll(numAttackDices);
	defenseDiceValues = defender->getDice()->roll(numDefenseDices);
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

	int compareCount = min(attackDiceValues.size(), defenseDiceValues.size());

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

	attackingCountry->setArmyNumber(attackArmySize - attackerLost);
	defendingCountry->setArmyNumber(defendArmySize - defenderLost);

	cout << "\nAttacker: " << attackingCountry->getCountryName() << " has " << attackingCountry->getArmyNumber() << " armies left." << endl;
	cout << "Defender: " << defendingCountry->getCountryName() << " has " << defendingCountry->getArmyNumber() << " armies left." << endl;

}

// check if defending country army size is 0 and change ownership of countries between players
void AttackPhase::isConquered() {
	if (defendingCountry->getArmyNumber() == 0) {
		defender->removeCountry(defendingCountry);
		attacker->addCountry(defendingCountry);
		cout << defenderName << " has lost " << defendingCountry->getCountryName() << endl;
		cout << attackerName << " has conquered " << defendingCountry->getCountryName() << endl;
	}

}