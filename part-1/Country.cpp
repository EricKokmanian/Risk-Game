#include <iostream>

using namespace std;
#include "Country.h"
#include "Player.h"

Country::Country() {
	name = "";
	owner = NULL;
	armyNumber = 0;
}

Country::Country(string countryName) {
	name = countryName;
	owner = NULL;
	armyNumber = 0;
}

Country::Country(string countryName, Player* player) {
	name = countryName;
	owner = player;
	armyNumber = 0;
}

Country::Country(string countryName, Player* player, int armyNumber) {
	name = countryName;
	owner = player;
	armyNumber = armyNumber;
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

