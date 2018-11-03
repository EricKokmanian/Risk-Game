#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

#include "Country.h"

class Map {

public:
	Map();
	int getSize();
	unordered_map<string, Country*>& getWorldMap();
	void addCountry(string countryName, Country* countryPtr);
	Country* getCountry(string);
	bool ifConnectedGraph(Country*);
	bool ifConnectedContinent(Country*, Continent*);

private:
	unordered_map<string, Country*> worldMap;
};