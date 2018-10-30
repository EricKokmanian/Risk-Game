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
	return countriesOwned;
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
