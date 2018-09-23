#pragma once

#include <iostream>
#include <string>
using namespace std;
#include "Player.h"

class Country {

	public:
		Country();
		Country(string countryName);
		Country(string countryName, Player* player);
		Country(string countryName, Player* player, int armyNumber);

		string getCountryName();
		void setCountryName(string countryName);
		Player* getOwner();
		void setOwner(Player* player);

	private:
		string name;
		Player* owner;
		int armyNumber;
};