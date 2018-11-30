#include <iostream>

using namespace std;
#include "Country.h"
#include "Player.h"

Country::Country() {
	name = "";
	armyNumber = 0;
	visited = false;
	continent = NULL;
}

Country::Country(string countryName) {
	name = countryName;
	armyNumber = 0;
	visited = false;
	continent = NULL;
}

Country::Country(string countryName, Player* player) {
	name = countryName;
	owner = player;
	armyNumber = 0;
	visited = false;
	continent = NULL;
}

Country::Country(string countryName, Player* player, int number) {
	name = countryName;
	owner = player;
	armyNumber = number;
	visited = false;
	continent = NULL;
}

Country::Country(string countryName, Player* player, int number, Continent* continentName) {
	name = countryName;
	owner = player;
	armyNumber = number;
	visited = false;
	continent = continentName;
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

string Country::getOwnerName() {
	return owner->getName();
}

void Country::setOwner(Player* player) {
	owner = player;
}

bool Country::getVisited() {
	return visited;
}

void Country::setVisited(bool value) {
	visited = value;
}

int Country::getArmyNumber() {
	return armyNumber;
}

void Country::setArmyNumber(int number) {
	armyNumber = number;
}

void Country::addArmy(int number) {
	armyNumber += number;
}

Continent * Country::getContinent()
{
	return continent;
}

void Country::setContinent(Continent* continentName) {
	continent = continentName;
}

void Country::addAdjacentCountry(Country* countryObject) {
	adjacentCountries.push_back(countryObject);
}
vector<Country*>& Country::getAdjacentCountries() {
	return adjacentCountries;
}

void Country::printAdjacentCountry() {
	for (auto it = adjacentCountries.begin(); it != adjacentCountries.end(); ++it) {
		cout << (*it)->getCountryName() << ", ";
	}
	cout << '\n';
}