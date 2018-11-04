#pragma once
#include <iostream>
#include "Player.h"
#include "Country.h"
#include "Continent.h"
#include "Map.h"

class FortificationPhase {

public:
	FortificationPhase();
	FortificationPhase(Player*);
	void moveArmy();
	void selectFromCountry();
	void selectToCountry();



private:
	Player* player;
	Country* fromCountry;
	Country* toCountry;

};