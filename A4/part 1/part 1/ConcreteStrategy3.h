#pragma once
#include "Strategy.h"
#include "Player.h"
#include "Map.h"

using namespace std;

// Class that will adopt the RANDOM PLAYER STRATEGY
class ConcreteStrategy3 : public Strategy {
public:
	ConcreteStrategy3();
	~ConcreteStrategy3();
	void reinforce(Map*, Player*);
	void attack(Player*);
	void fortify(Player*);
	void chooseCountry();
	void chooseDice();
	void rollingDice();
	void isConquered();

private:
	vector<Country*> defenderCountries;
	vector<Country*> attackerCountries;
	Country* attackingCountry;
	Country* defendingCountry;
	Player* attacker;
	Player* defender;
	int attackArmySize;
	int defendArmySize;
	int numAttackDices;
	int numDefenseDices;
	string attackerName;
	string defenderName;
	int attackerLost;
	int defenderLost;
};

