#include "ConcreteStrategy4.h"
#include "FortificationPhase.h"
#include "AttackPhase.h"
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>

using namespace std;



ConcreteStrategy4::ConcreteStrategy4()
{
}


ConcreteStrategy4::~ConcreteStrategy4()
{
}

void ConcreteStrategy4::reinforce(Map* worldmap, Player *player)
{
	int x = worldmap->getNumberOfCountries(*player);
	if (x < 3) {
		x = 3;
	}

	string name;
	cout << "Here are the countries owned by " << player->getName() << " : " << player->getCountries(1) << endl << "We will double all the armies of these countries " << endl;
	for (int a = 0;a < player->getCountries().size(); a++) {
		cout << player->getCountries()[a]->getCountryName() << " had " << player->getCountries()[a]->getArmyNumber() << " armies. ";
		player->getCountries()[a]->setArmyNumber(player->getCountries()[a]->getArmyNumber() * 2);
		cout << "Now it has: " << player->getCountries()[a]->getArmyNumber() << " armies." << endl;
	}

	cout << "-------- END OF REINFORCEMENT PHASE ---------" << endl;
}

void ConcreteStrategy4::attack(Player *player)
{
	cout << "Conquering all neighboring countries of " << player->getName() << endl << endl;

	for (int i = 0;i < player->getCountries().size(); i++) {
		cout << player->getCountries()[i]->getCountryName() << " has the following neighboring countries : " << endl;
		for (int x = 0;x < player->getCountries()[i]->getAdjacentCountries().size();x++) {
			cout << player->getCountries()[i]->getAdjacentCountries()[x]->getCountryName() << endl;
			player->getCountries()[i]->getAdjacentCountries()[x]->setOwner(player);

			//adding the country into player's countries vector
			if (find(player->getCountries().begin(), player->getCountries().end(), player->getCountries()[i]->getAdjacentCountries()[x]) != player->getCountries().end()) {
				/* player contains the country */
			}
			else {
				player->addCountry(player->getCountries()[i]->getAdjacentCountries()[x]);
			}
		}
	}
	cout << "These countries are now all owned by " << player->getName() << endl << endl;

	cout << "Here are all the countries owned by " << player->getName() << " :" << player->getCountries(1)<<endl;

	cout << "-------- END OF ATTACK PHASE ---------" << endl;
}

void ConcreteStrategy4::fortify(Map worldMap,Player *player)
{
	for (auto const &ent1 : worldMap.getMap()) {
		if (ent1.second->getOwner() != player) {
			cout << "The neighboring country "<< ent1.second->getCountryName() << " is owned by " << ent1.second->getOwnerName() << endl;
			cout << ent1.second->getCountryName() << " has " << ent1.second->getArmyNumber() << " armies. " << endl;
			ent1.second->setArmyNumber(ent1.second->getArmyNumber() * 2);
			cout << "It now has " << ent1.second->getArmyNumber() << " armies!" << endl;
		}
	}



	cout << "-------- END OF FORTIFY PHASE ---------" << endl;
}

void ConcreteStrategy4::chooseCountry()
{
	cout << "You're gonna attack with " << attackingCountry->getCountryName() << endl;
	system("pause");

	srand(time(0));
	int randomCountryIndex = rand() % defenderCountries.size();

	defendingCountry = defenderCountries[randomCountryIndex];
	defender = defendingCountry->getOwner();
	cout << defendingCountry->getCountryName() << " has been randomly chosen as the target country" << endl;
	system("pause");
}

void ConcreteStrategy4::chooseDice()
{
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

void ConcreteStrategy4::rollingDice()
{
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

void ConcreteStrategy4::isConquered()
{
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
