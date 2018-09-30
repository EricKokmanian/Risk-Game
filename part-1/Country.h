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
		Country(string countryName, Player* player, int armyNumber);
		Country(string countryName, Player* player, int armyNumber, Continent* continentName);

		string getCountryName();
		void setCountryName(string countryName);
		Player* getOwner();
		void setOwner(Player* player);
		int getArmyNumber();
		void setArmyNumber(int number);
		Continent* getContinent();
		void setContinent(Continent* continentName);
		void addAdjacentCountry(Country* countryObject);
		vector<Country*> getAdjacentCountries();
		void printAdjacentCountry();

	private:
		string name;
		Player* owner;
		int armyNumber;
		Continent* continent;
		vector<Country*> adjacentCountries;
		
};