#pragma once
#include "Map.h"
#include "Player.h"

using namespace std;

class Player;
class Map;

// Interface
class Strategy {
	public:
		Strategy();
		virtual void reinforce(Map* map, Player* pl) = 0;
		virtual void attack(Player*) = 0;
		virtual void fortify(Player*) = 0;
	private:
};
