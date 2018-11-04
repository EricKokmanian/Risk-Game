#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Continent.h"

using namespace std;

class Player;
class Country {
	
public:
	Country();
	Country(string countryName);
	Country(string countryName, Continent* continentName);

	string getCountryName();
	void setCountryName(string countryName);
	Player* getOwner();
	void setOwner(Player* player);
	int getArmyNumber();
	void setArmyNumber(int number);
	bool getVisited();
	void setVisited(bool);
	Continent* getContinent();
	void setContinent(Continent* continentName);
	void addAdjacentCountry(Country* countryObject);
	vector<Country*>& getAdjacentCountries();
	void printAdjacentCountry();

private:
	string name;
	Player* owner;
	int armyNumber;
	bool visited;
	Continent* continent;
	vector<Country*> adjacentCountries;

};