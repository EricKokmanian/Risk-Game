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
		Country(string countryName, Player* player);
		Country(string countryName, Player* player, int armyNbr);
		Country(string countryName, Player* player, int armyNbr, Continent* contName);
		
		string getCountryName();
		void setCountryName(string countryName);
		Player* getOwner();
		void setOwner(Player* player);
		int getArmyNumber();
		void setArmyNumber(int nbr);
		Continent* getContinent();
		void setContinent(Continent* contName);
	
	private :
		string name;
		Player* owner;
		int armyNbr;
		Continent* continent;
};