#pragma once

#include "GameEngine.h"

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
		Player* player;
		Country* attackingCountry;
		Country* defendingCountry;

};