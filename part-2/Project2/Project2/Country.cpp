#include <iostream>

using namespace std;

#include "Country.h"
#include "Player.h"

Country::Country() {
	name = "";
	owner = NULL;
	armyNbr = 0;
	continent = NULL;
}

Country::Country(string countryName) {
	name = countryName;
	owner = NULL;
	armyNbr = 0;
	continent = NULL;
}

Country::Country(string countryName, Player* player) {
	name = countryName;
	owner = player;
	armyNbr = 0;
	continent = NULL;
}

Country::Country(string countryName, Player* player, int nbr) {
	name = countryName;
	owner = player;
	armyNbr = nbr;
	continent = NULL;
}

Country::Country(string countryName, Player* player, int nbr, Continent* contName) {
	name = countryName;
	owner = player;
	armyNbr = nbr;
	continent = contName;
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

Continent* Country::getContinent() {
	return continent;
}

void Country::setContinent(Continent* contName) {
	continent = contName;
}

void Country::addAdjacentCountry(Country* neighbor) {
	adjacentCountries.push_back(neighbor);
}

vector<Country*> Country::getAdjacentCountries() {
	return adjacentCountries;
}