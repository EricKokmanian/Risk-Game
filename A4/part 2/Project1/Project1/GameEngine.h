#pragma once

#include <iostream>
#include "Continent.h"
#include "Country.h"
#include "Dice.h"
#include "Map.h"
#include "Player.h"
#include "AttackPhase.h"

using namespace std;

class GameEngine {
public:
	GameEngine();
	void addPlayer(Player*);
	void declareAttack(Player*);
private:
	vector<Player*> players;
};


