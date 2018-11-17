#include <iostream>
#include <queue>
#include "Map.h"
#include "Country.h"
#include "Continent.h"
#include "Player.h"

using namespace std;

Map::Map() {

}

void Map::addCountry(string countryName, Country* countryObject) {
	worldMap[countryName] = countryObject;
}

int Map::getNumberOfCountries(Player player)
{
	int countriesOwned = 0;
	for (auto& x : worldMap)
	{
		if (x.second->getOwnerName() == player.getName()) {
			countriesOwned++;
		}
	}
	double value = countriesOwned / 3;
	int newValue = floor(value);
	return newValue;
}

Country* Map::getCountry(string country)
{
	for (auto& x : worldMap)
	{
		if (x.second->getCountryName() == country) {
			return x.second;
		}
	}
	return NULL;
}

bool Map::isWinner(Player* plyr) {
	for (auto it = worldMap.begin(); it != worldMap.end(); ++it) {
		if ((*it).second->getOwner() != plyr)
			return false;
	}
	return true;
}
