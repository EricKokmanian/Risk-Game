#pragma once
#include <iostream>
#include <unordered_map>
#include "Country.h"
#include "Subject.h"

using namespace std;

class Country;
class Map : public Subject {
public:
	Map();
	void addCountry(string, Country*);
	bool ifConnectedGraph(Country*);
	bool ifConnectedContinent(Country*, Continent*);
	void setOwner(Country* c, Player* p);
	unordered_map<string, Country*> getMap();

private:
	unordered_map<string, Country*> worldMap;

};
