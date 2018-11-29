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
	void reinforce(Map, Player*);
	void attack(Player*);
	void fortify(Map, Player*);
private:

};


