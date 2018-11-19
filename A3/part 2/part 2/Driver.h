#pragma once
#include "Country.h"
#include "Player.h"
#include "Continent.h"
#include "Map.h"
#include "Subject.h"

#include <vector>

using namespace std;
class Driver: public Subject
{
private:
	Player* player;
public:
	Driver();
	~Driver();
	void start();
	Player* getPlayer();
	void reinforce(Map worldmap, Player* player);
	void reinforce2(Map worldmap, Player* player);
	void reinforce3(Map worldmap, Player player);
	void attack(Player* p);
	void fortify(Player* p);
	bool reinforcing;
};

