#pragma once

#include "GameEngine.h"
#include "Dice.h"
#include "Map.h"

using namespace std;

class AttackPhase {
	public:
		AttackPhase();
		AttackPhase(Map* map);
		void setPlayer(Player*);
		void attack();
		void chooseCountry();
		void chooseDice();
		void rollingDice();
		void isConquered();

	private:
		Player* attacker;
		Player* defender;
		// player names
		string attackerName;
		string defenderName;
		Country* attackingCountry;
		Country* defendingCountry;
		// number of dices chosen by the attacker and defender
		int numAttackDices;
		int numDefenseDices;
		// number of army lost
		int attackerLost;
		int defenderLost;
		// number of army on country
		int attackArmySize;
		int defendArmySize;
		Map* map;

};