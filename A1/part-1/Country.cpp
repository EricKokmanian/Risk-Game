#include <iostream>
#include "Country.h"
#include "Player.h"

using namespace std;


Country::Country() {
	name = "";
	owner = NULL;
	armyNumber = 0;
	visited = false;
	continent = NULL;
}

Country::Country(string countryName) {
	name = countryName;
	owner = NULL;
	armyNumber = 0;
	visited = false;
	continent = NULL;
}

Country::Country(string countryName, Continent* continentName) {
	name = countryName;
	owner = NULL;
	armyNumber = 0;
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

void Country::setOwner(Player* player) {
	owner = player;
}

int Country::getArmyNumber() {
	return armyNumber;
}

void Country::setArmyNumber(int number) {
	armyNumber = number;
}

bool Country::getVisited() {
	return visited;
}

void Country::setVisited(bool value) {
	visited = value;
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