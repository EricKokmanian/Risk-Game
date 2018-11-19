#pragma once

#include "GameEngine.h"
#include "Player.h"
#include "Dice.h"
#include "Subject.h"

using namespace std;

class AttackPhase: public Subject {
public:
	AttackPhase();
	void setPlayer(Player*);
	void attack();
	void chooseCountry();
	void chooseDice();
	void rollingDice();
	void isConquered();
	string getAttackerName();
	string getDefenderName();
	Player* getAttacker();
	Player* getDefender();
	int getAttackArmySize();
	int getDefendArmySize();
	bool keepAttacking;

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

};
