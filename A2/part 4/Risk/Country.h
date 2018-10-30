#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Continent.h"

class Player;

class Country {

public:
	Country();
	Country(string countryName);
	Country(string countryName, Player* player);
	Country(string countryName, Player* player, int armyNumber);
	Country(string countryName, Player* player, int armyNumber, Continent* continentName);

	string getCountryName();
	void setCountryName(string countryName);
	string getOwnerName();
	void setOwner(Player* player);
	int getArmyNumber();
	void setArmyNumber(int number);
	void addArmy(int number);
	Continent* getContinent();
	void setContinent(Continent* continentName);
	void addAdjacentCountry(Country* countryObject);
	vector<Country*> getAdjacentCountries();
	void printAdjacentCountry();

public:
	string name;
	Player* owner;
	int armyNumber=0;
	Continent* continent;
	vector<Country*> adjacentCountries;

};