#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Player.h"
#include "Continent.h"

class Country {

public:
	Country();
	Country(string countryName);
	Country(string countryName, Player* player);
	Country(string countryName, Player* player, int nbr);
	Country(string countryName, Player* player, int nbr, Continent* contName);

	string getCountryName();
	void setCountryName(string countryName);
	Player* getOwner();
	void setOwner(Player* player);
	int getArmyNumber();
	void setArmyNumber(int nbr);
	Continent* getContinent();
	void setContinent(Continent* contName);
	void addAdjacentCountry(Country* neighbor);
	vector<Country*> getAdjacentCountries();

private:
	string name;
	Player* owner;
	int armyNbr;
	Continent* continent;
	vector<Country*> adjacentCountries;
};
