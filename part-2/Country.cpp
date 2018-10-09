#include <iostream>

using namespace std;

#include "Country.h"
#include "Player.h"

Country::Country() {
	name = "";
	owner = NULL;
	armyNbr = 0;
}

Country::Country(string countryName) {
	name = countryName;
	owner = NULL;
	armyNbr = 0;
}

Country::Country(string countryName, Player* player) {
	name = countryName;
	owner = player;
	armyNbr = 0;
}

Country::Country(string countryName, Player* player, int nbr) {
	name = countryName;
	owner = player;
	armyNbr = nbr;
}

string Country::getCountryName() {
	return name;
}

void Country::setCountryName(string countryName) {
	name = countryName;
}

Player* Country::getOwner() {
		return owner;
}

void Country::setOwner(Player* player) {
	owner = player;
}

int Country::getArmyNumber() {
		return armyNbr;
}

void Country::setArmyNumber(int nbr) {
		armyNbr = nbr;
}