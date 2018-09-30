#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;
#include "Country.h"

class Map {
public:
	Map();
	void addCountry(string, Country*);
	//bool ifConnectedGraph();
	//bool ifConnectedContinent(Continent*);

private: 
	unordered_map<string, Country*> worldMap;

};
