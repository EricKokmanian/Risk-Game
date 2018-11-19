#pragma once
#include <iostream>
#include "Player.h"
#include "Country.h"
#include "Continent.h"
#include "Map.h"
#include "Subject.h"

class FortificationPhase: public Subject {

public:
	FortificationPhase();
	FortificationPhase(Player*);
	void setPlayer(Player*);
	Player* getPlayer();
	void moveArmy();
	void selectFromCountry();
	void selectToCountry();
	void selectArmySize();
	bool fortifying;


private:
	Player* player;
	Country* fromCountry;
	Country* toCountry;

};
