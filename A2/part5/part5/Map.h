#pragma once
#include <iostream>
#include <unordered_map>
#include "Country.h"

using namespace std;

class Map {
public:
	Map();
	void addCountry(string, Country*);
	bool ifConnectedGraph(Country*);
	bool ifConnectedContinent(Country*, Continent*);

private:
	unordered_map<string, Country*> worldMap;

};
