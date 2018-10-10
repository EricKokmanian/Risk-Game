#include <iostream>

using namespace std;

#include "Map.h"

Map::Map() {
	unordered_map<string, Country*> worldMap;
}

void Map::addCountry(string countryName, Country* countryPtr) {
	worldMap["countryName"] = countryPtr;
}

//bool Map::ifConnected() {
//	//BFS checking all countries
//}

 //bool Map::ifConnectedCont(Continent* continent) {
//	//BFS checking countries with the continentObject as Continent* variable
//} 