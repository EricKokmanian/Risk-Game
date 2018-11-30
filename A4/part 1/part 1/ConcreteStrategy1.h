
#pragma once
#include "Strategy.h"
#include "Player.h"
#include "Map.h"

using namespace std;

// Class that will adopt the AGGRESSIVE PLAYER STRATEGY
class ConcreteStrategy1 : public Strategy {
public:
	ConcreteStrategy1();
	void reinforce(Map*, Player*);
	void attack(Player*);
	void fortify(Map,Player*);
private:
	Country * attackingCountry;
	Country* defendingCountry;
	Player* attacker;
	Player* defender;
};
