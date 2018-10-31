#pragma once

#include "GameEngine.h"
#include "Dice.h"

using namespace std;

class AttackPhase {
	public:
		AttackPhase();
		void setPlayer(Player*);
		void attack();
		void chooseCountry();
		void chooseDice();
		void rollingDice();

	private:
		Player* attacker;
		Player* defender;
		Country* attackingCountry;
		Country* defendingCountry;
		// number of dices chosen by the attacker and defender
		int numAttackDices;
		int numDefenseDices;
		// number of army lost
		int attackerLost;
		int defenderLost;

};