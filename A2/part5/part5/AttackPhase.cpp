#include <iostream>
#include <algorithm>
#include <string>
#include "AttackPhase.h"

using namespace std;

AttackPhase::AttackPhase() {
	numAttackDices = 0;
	numDefenseDices = 0;
}

void AttackPhase::setPlayer(Player* player) {
	this->attacker = player;
}

// starts and ends the attack phase
void AttackPhase::attack() {
	bool keepAttacking = true;
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
		break;
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
}

// setup the dices to be rolled
void AttackPhase::chooseDice() {
	int attackArmySize = attackingCountry->getArmyNumber();
	string attackerName = attacker->getName();
	int defendArmySize = defendingCountry->getArmyNumber();
	string defenderName = defender->getName();

	cout << "============" << attackingCountry->getCountryName() << " OWNED BY " << attackerName << " IS ATTACKING "
		<< defendingCountry->getCountryName() << " OWNED BY " << defenderName << "============" << endl;
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

	int attackArmySize = attacker->getNumberOfArmy();
	int defendArmySize = defender->getNumberOfArmy();
	attacker->setNumberOfArmy(attackArmySize - attackerLost);
	defender->setNumberOfArmy(defendArmySize - defenderLost);
}