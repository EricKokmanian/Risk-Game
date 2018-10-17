#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Player.h"
#include "Continent.h"

class Country {

	public :
		Country();
		Country(string countryName);
		Country(string countryName, Continent* continentName);
		
		string getCountryName();
		void setCountryName(string countryName);
		Player* getOwner();
		void setOwner(Player* player);
		int getArmyNumber();
		void setArmyNumber(int nbr);
		bool getVisited();
		void setVisited(bool);
		Continent* getContinent();
		void setContinent(Continent* contName);
		void addAdjacentCountry(Country* neighbor);
		vector<Country*> getAdjacentCountries();
		void printAdjacentCountry();
	
	private :
		string name;
		Player* owner;
		int armyNbr;
		bool visited;
		Continent* continent;
		vector<Country*> adjacentCountries;
};