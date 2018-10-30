#pragma once
#include <iostream>
#include <unordered_map>
#include "Country.h"

using namespace std;

class Map {
public:
	Map();
	void addCountry(string, Country*);
	int getNumberOfCountries(Player player);
	Country* getCountry(string country);
	unordered_map<string, Country*> getMap() { return worldMap; }

private:
	unordered_map<string, Country*> worldMap;
};