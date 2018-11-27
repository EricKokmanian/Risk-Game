#include <iostream>
#include <time.h>
#include <algorithm>

#include "ConcreteStrategy3.h"

using namespace std;

ConcreteStrategy3::ConcreteStrategy3() {

}

ConcreteStrategy3::~ConcreteStrategy3() {
	
}

void ConcreteStrategy3::reinforce(Map* map, Player* player) {
	int x = map->getNumberOfCountries(*player);
	if (x < 3) {
		x = 3;
	}

	string name;
	cout << "-------------START OF REINFORCEMENT PHASE-------------\n" << endl;
	cout << "\nNUMBER OF COUNTRIES BY " << player->getName() << " : " << x << endl;
	cout << "Here are the countries owned by " << player->getName() << ": " << endl;
	vector<Country*> countries = player->getCountries();

	for (auto it = countries.begin(); it != countries.end(); ++it) {
		cout << "- " << (*it)->getCountryName() << " with armies value of " << (*it)->getArmyNumber() << endl;
	}
	system("pause");

	cout << "\nThere are " << x << " armies to place." << endl;

	srand(time(0));
	int value = rand() % (countries.size());
	countries[value]->setArmyNumber(countries[value]->getArmyNumber() + x);

	cout << countries[value]->getCountryName() << " has just been reinforced randomly." << endl;
	cout << "NUMBER OF ARMIES OF " << countries[value]->getCountryName() << " : " << countries[value]->getArmyNumber() << endl;

	cout << "\n       -------- END OF REINFORCEMENT PHASE ---------\n" << endl;
	system("pause");

}

void ConcreteStrategy3::attack(Player* player) {
	attacker = player;
	srand(time(0));
	// limiting attacks to 10 or upper limit would be infinite
	int numberOfAttack = rand() % 11;
	cout << "\n-------------START OF ATTACK PHASE-------------\n\n" << endl;

	// display countries of attacker
	cout << attacker->getName() << ", these are your countries: " << endl;
	for (auto it = player->getCountries().begin(); it != player->getCountries().end(); ++it) {
		cout << "- " << (*it)->getCountryName() << " with army values of " << (*it)->getArmyNumber() << endl;
		if ((*it)->getArmyNumber() > 1) {
			attackerCountries.push_back(*it);
		}
	}
	system("pause");

	while (true) {
		// randomly selects attacking country
		srand(time(0));
		int randomCountryIndex = rand() % attacker->getCountries().size();
		attackingCountry = attacker->getCountries()[randomCountryIndex];
		// search for enemy countries surrounding the selected attacking country
		for (auto it = attackingCountry->getAdjacentCountries().begin(); it != attackingCountry->getAdjacentCountries().end(); ++it) {
			if ((*it)->getOwner() != attacker) {
				defenderCountries.push_back((*it));
			}
		}
		// if not enough army size
		if (attackingCountry->getArmyNumber() < 2) {

		}
		// if there are no defending countries
		else if (defenderCountries.size() == 0) {

		}
		else {
			// attacker chooses which country to attack
			keepAttacking = true;
			chooseCountry();
			for (int i = 0; i < numberOfAttack; i++) {
				cout << "\nTHIS IS ATTACK " << i + 1 << "/" << numberOfAttack;
				// attacker and defender choose the number of dices to roll
				chooseDice();
				// game rolls the dices and declares the winner and reduces army sizes accordingly
				rollingDice();
				// if defending country has 0 army, ownership is transfered to the attacker and can move his army
				isConquered();
				if (keepAttacking == false) {
					return;
				}
			}
			return;
		}
	}
}

void ConcreteStrategy3::chooseCountry() {
	cout << "You're gonna attack with " << attackingCountry->getCountryName() << endl;
	system("pause");

	srand(time(0));
	int randomCountryIndex = rand() % defenderCountries.size();
	
	defendingCountry = defenderCountries[randomCountryIndex];
	defender = defendingCountry->getOwner();
	cout << defendingCountry->getCountryName() << " has been randomly chosen as the target country" << endl;
	system("pause");
}

void ConcreteStrategy3::chooseDice(){
	attackArmySize = attackingCountry->getArmyNumber();
	defendArmySize = defendingCountry->getArmyNumber();
	cout << "\n============" << attackingCountry->getCountryName() << " OWNED BY " << attacker->getName() << " IS ATTACKING "
		<< defendingCountry->getCountryName() << " OWNED BY " << defender->getName() << "============\n" << endl;
	cout << "Attacker: " << attackingCountry->getCountryName() << " has an army of " << attackArmySize << endl;
	cout << "Defender: " << defendingCountry->getCountryName() << " has an army of " << defendArmySize << endl;
	system("pause");

	attackerName = attackingCountry->getOwnerName();
	defenderName = defendingCountry->getOwnerName();

	if (attackArmySize == 2) {
		cout << attackerName << ", you are attacking with 1 dice" << endl;
		numAttackDices = 1;
		system("pause");
	}
	else if (attackArmySize == 3) {
		cout << attackerName << ", you are attacking with 2 dices" << endl;
		numAttackDices = 2;
		system("pause");
	}
	else if (attackArmySize < 2) {
		cout << "You can't attack anymore" << endl;
		keepAttacking = false;
		return;
	}
	else {
		cout << attackerName << ", you are attacking with 3 dices" << endl;
		numAttackDices = 3;
		system("pause");
	}

	if (defendArmySize == 1) {
		cout << defenderName << ", you can defending with 1 dice" << endl;
		numDefenseDices = 1;
		system("pause");
	}
	else {
		cout << defenderName << ", you are defending with 2 dices" << endl;
		numDefenseDices = 2;
		system("pause");
	}
}

void ConcreteStrategy3::rollingDice() {
	vector<int> attackDiceValues;
	vector<int> defenseDiceValues;
	attackerLost = 0;
	defenderLost = 0;
	if (keepAttacking == false) {
		return;
	}

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
	size_t compareCount = min(attackDiceValues.size(), defenseDiceValues.size());
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
	system("pause");

	cout << "\nAttacker: " << attackingCountry->getCountryName() << " has " << attackingCountry->getArmyNumber() << " armies left." << endl;
	cout << "Defender: " << defendingCountry->getCountryName() << " has " << defendingCountry->getArmyNumber() << " armies left." << endl;
}

void ConcreteStrategy3::isConquered() {
	if (defendingCountry->getArmyNumber() == 0) {
		// transfer ownership of country
		defendingCountry->setOwner(attacker);
		// set the army size of newly conquered country to remaining attacking army
		defendingCountry->setArmyNumber(numAttackDices - attackerLost);
		attackingCountry->setArmyNumber(attackArmySize - defendingCountry->getArmyNumber());
		defender->removeCountry(defendingCountry);
		attacker->addCountry(defendingCountry);
		defendingCountry->setOwner(attacker);
		cout << defenderName << " has lost " << defendingCountry->getCountryName() << endl;
		cout << attackerName << " has conquered " << defendingCountry->getCountryName() << endl;
		keepAttacking = false;
		system("pause");
	}
}


void ConcreteStrategy3::fortify(Player* player) {
	vector<Country*> fortifyFromCountry;
	vector<Country*> fortifyToCountry = player->getCountries();
	cout << "\n------------------- START OF FORTIFICATION PHASE --------------------\n " << endl;

	cout << "These are the countries you can fortify from (at least 2 armies): " << endl;
	for (auto it = player->getCountries().begin(); it != player->getCountries().end(); ++it) {
		if ((*it)->getArmyNumber() > 1) {
			cout << " -" << (*it)->getCountryName() << " with an army of " << (*it)->getArmyNumber() << endl;
			fortifyFromCountry.push_back(*it);
		}
	}
	system("pause");

	srand(time(0));
	int randomFromCountryIndex = rand() % fortifyFromCountry.size();
	fromCountry = fortifyFromCountry[randomFromCountryIndex];
	if (fortifyFromCountry.size() == 1) {
		cout << "You only have one country, so you can't fortify" << endl;
		cout << "\n------------------- END OF FORTIFICATION PHASE --------------------\n " << endl;
		return;
	}
	cout << "You're gonna move armies from " << fromCountry->getCountryName() << endl;		
	system("pause");

	while (true) {
		srand(time(0));
		int randomToCountryIndex = rand() % fortifyFromCountry.size();
		if (fortifyToCountry[randomToCountryIndex]->getCountryName() != fromCountry->getCountryName()) {
			toCountry = fortifyToCountry[randomToCountryIndex];
			cout << "You're gonna move armies to " << toCountry->getCountryName() << endl;
			break;
		}
	}

	srand(time(0));
	int valueToFortify = rand() % fromCountry->getArmyNumber();
	cout << "Random number of armies to fortify with is: " << valueToFortify << endl;
	int fromCountrySize = fromCountry->getArmyNumber();
	int toCountrySize = toCountry->getArmyNumber();
	fromCountry->setArmyNumber(fromCountrySize - valueToFortify);
	toCountry->setArmyNumber(toCountrySize + valueToFortify);
	cout << fromCountry->getCountryName() << " has now " << fromCountry->getArmyNumber() << endl;
	cout << toCountry->getCountryName() << " has now " << toCountry->getArmyNumber() << endl;
	cout << "\n------------------- END OF FORTIFICATION PHASE --------------------\n " << endl;
	system("pause");

}