#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

#include "Country.h"

class Map {

public:
	Map();
	void addCountry(string countryName, Country* countryPtr);
	bool ifConnectedGraph(Country*);
	bool ifConnectedContinent(Country*, Continent*);

private:
	unordered_map<string, Country*> worldMap;
};