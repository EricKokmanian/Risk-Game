#include <iostream>
#include "Map.h"

using namespace std;

Map::Map() {
	unordered_map<string, Country*> worldMap;
}

void Map::addCountry(string countryName, Country* countryObject) {
	worldMap["countryName"] = countryObject;
}

//bool Map::ifConnectedGraph() {
//	//BFS checking all countries
//}

//bool Map::ifConnectedContinent(Continent* continentObject) {
//	//BFS checking countries with the continentObject as Continent* variable
//}