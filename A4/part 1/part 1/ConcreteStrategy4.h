#pragma once
#include "Strategy.h"
#include "Player.h"
#include "Map.h"

using namespace std;

// Class that will adopt the CHEATER PLAYER STRATEGY
class ConcreteStrategy4 : public Strategy {
	public:
		ConcreteStrategy4();
		~ConcreteStrategy4();
		void reinforce(Map*, Player*);
		void attack(Player*);
		void fortify(Map, Player*);
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
		Country* fromCountry;
		Country* toCountry;
		bool keepAttacking;
};

