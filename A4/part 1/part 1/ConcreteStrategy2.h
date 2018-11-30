#pragma once
#include "Strategy.h"
#include "Player.h"
#include "Map.h"

using namespace std;

// Class that will adopt the PASSIVE PLAYER STRATEGY
class ConcreteStrategy2 : public Strategy {
	public:
		ConcreteStrategy2();
		void reinforce(Map*, Player*);
		void attack(Player*);
		void fortify(Map,Player*);
	private:

};
