#pragma once
#include <iostream>
#include <unordered_map>
#include "Country.h"
#include "Player.h"

using namespace std;

class Map {
public:
	Map();
	void addCountry(string, Country*);
	int getNumberOfCountries(Player player);
	Country* getCountry(string country);
	unordered_map<string, Country*> getMap() { return worldMap; }
	bool isWinner(Player*);

private:
	unordered_map<string, Country*> worldMap;
};

