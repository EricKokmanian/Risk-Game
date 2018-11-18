#include <iostream>
#include <algorithm>
#include <string>
#include "AttackPhase.h"
#include "Map.h"

using namespace std;

AttackPhase::AttackPhase() {
	numAttackDices = 0;
	numDefenseDices = 0;
	attackerLost = 0;
	defenderLost = 0;
}

AttackPhase::AttackPhase(Map * map)
{
	this->map = map;
}

void AttackPhase::setPlayer(Player* player) {
	this->attacker = player;
}

// starts and ends the attack phase
void AttackPhase::attack() {
	bool keepAttacking = true;
	string playerAnswer = "";
	while (keepAttacking) {
		int counter = 1;
		cout << "Please enter the corresponding number of the country you want to attack with: " << endl;
		vector<Country*>::size_type size = attacker->getCountries().size();
		for (vector<Country*>::size_type i = 0; i < size; ++i) {
			cout << counter << ". " << attacker->getCountries()[i]->getCountryName()
				<< "      with an army of " << attacker->getCountries()[i]->getArmyNumber() << endl;
			counter++;
		}
		int playerChoice = 0;
		cin >> playerChoice;
		// player selects attacking country
		attackingCountry = attacker->getCountries()[playerChoice - 1];
		// search for enemy countries surrounding the selected attacking country
		vector<Country*> defendingCountries;
		for (auto it = attackingCountry->getAdjacentCountries().begin(); it != attackingCountry->getAdjacentCountries().end(); ++it) {
			if ((*it)->getOwner() != attacker) {
				defendingCountries.push_back((*it));
			}
		}
		// if not enough army size
		if (attackingCountry->getArmyNumber() < 2) {
			cout << "You can only attack with a country of 2 or more armies." << endl;
		}
		// if there are no defending countries
		else if (defendingCountries.size() == 0) {
			cout << "There are no enemy countries surrounding " << attackingCountry->getCountryName() << endl;
		}
		else {
			// attacker chooses which country to attack
			chooseCountry();
			// attacker and defender choose the number of dices to roll
			chooseDice();
			// game rolls the dices and declares the winner and reduces army sizes accordingly
			rollingDice();
			// if defending country has 0 army, ownership is transfered to the attacker and can move his army
			isConquered();
		}
		
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

	cout << "You're gonna attack with " << attackingCountry->getCountryName() << endl;
	cout << "Enter the corresponding number of the country you want to attack: " << endl;

	int i = 1;
	vector<Country*> defendingCountries;
	// list all the countries that the attacker can attack
	for (auto it = attackingCountry->getAdjacentCountries().begin(); it != attackingCountry->getAdjacentCountries().end(); ++it) {
		if ((*it)->getOwner() != attacker) {
			defendingCountries.push_back((*it));
			cout << i << ". " << (*it)->getCountryName() << endl;
			i++;
		}
	}

	// attacker has chosen which country to attack, initialize variables
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
	attackerLost = 0;
	defenderLost = 0;

	// roll dices for both parties
	attackDiceValues = attacker->getDice()->roll(numAttackDices);
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
	attackingCountry->setArmyNumber(attackArmySize - attackerLost);
	defendingCountry->setArmyNumber(defendArmySize - defenderLost);

	cout << "\nAttacker: " << attackingCountry->getCountryName() << " has " << attackingCountry->getArmyNumber() << " armies left." << endl;
	cout << "Defender: " << defendingCountry->getCountryName() << " has " << defendingCountry->getArmyNumber() << " armies left." << endl;

}

// check if defending country army size is 0 and change ownership of countries between players
void AttackPhase::isConquered() {
	if (defendingCountry->getArmyNumber() == 0) {
		// transfer ownership of country
		map->setOwner(defendingCountry, attacker);
		// set the army size of newly conquered country to remaining attacking army
		defender->removeCountry(defendingCountry);
		attacker->addCountry(defendingCountry);
		cout << defenderName << " has lost " << defendingCountry->getCountryName() << endl;
		cout << attackerName << " has conquered " << defendingCountry->getCountryName() << endl;

		// move army after conquering defending country
		cout << attackerName << ", do you want to move your army from " << attackingCountry->getCountryName()
			<< " to " << defendingCountry->getCountryName() << "?" << endl;
		string playerChoice;
		cin >> playerChoice;
		if (playerChoice == "yes") {
			cout << attackingCountry->getCountryName() << " has an army of " << attackingCountry->getArmyNumber()
				<< " and " << defendingCountry->getCountryName() << " has an army of " << defendingCountry->getArmyNumber() << endl;
			cout << "How many armies do you want to move to " << defendingCountry->getCountryName() << "?" << endl;
			while (true) {
				int armySize = 0;
				cin >> armySize;
				if (armySize >= attackingCountry->getArmyNumber()) {
					cout << "You need to keep at least one army on " << attackingCountry->getCountryName() << endl;
				}
				else {
					int attackArmy = attackingCountry->getArmyNumber();
					int defendArmy = defendingCountry->getArmyNumber();
					attackingCountry->setArmyNumber(attackArmy - armySize);
					defendingCountry->setArmyNumber(defendArmy + armySize);
					cout << attackingCountry->getCountryName() << " has now " << attackingCountry->getArmyNumber() << endl;
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