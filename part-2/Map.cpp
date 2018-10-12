#include <iostream>

using namespace std;

#include "Map.h"

Map::Map() {
	unordered_map<string, Country*> worldMap;
}

unordered_map<string, Country*>& Map::getWorldMap() {
	return worldMap;
}

void Map::addCountry(string countryName, Country* countryPtr) {
	worldMap["countryName"] = countryPtr;
}	

bool Map::ifConnectedGraph(Country* countryObject) {
	// reset all countryObjects to false
	for (auto& country : worldMap) {
		Country *ptr = country.second;
		ptr->setVisited(false);
	}

	// queue for bfs
	queue<Country*> queue;
	queue.push(countryObject);

	while (!queue.empty()) {
		Country *ptr = queue.front();
		queue.pop();
		// set the first country has visited
		ptr->setVisited(true);
		for (auto it = ptr->getAdjacentCountries().begin(); it != ptr->getAdjacentCountries().end(); it++) {
			if ((*it)->getVisited() != true) {
				//set the country visited that is pushed in the queue
				(*it)->setVisited(true);
				queue.push(*it);
			}
		}

	}
	// check that that all countries have been visited, or return false
	for (auto& country : worldMap) {
		Country *ptr = country.second;
		if (!ptr->getVisited()) {
			return false;
		}
	}
	return true;
}

bool Map::ifConnectedContinent(Country* countryObject, Continent* continentObject) {
	// reset all visited countries to false
	for (auto& country : worldMap) {
		Country *ptr = country.second;
		ptr->setVisited(false);
	}

	// queue for bfs
	queue<Country*> queue;
	queue.push(countryObject);

	while (!queue.empty()) {
		Country *ptr = queue.front();
		queue.pop();
		// set the first country has visited
		ptr->setVisited(true);
		for (auto it = ptr->getAdjacentCountries().begin(); it != ptr->getAdjacentCountries().end(); it++) {
			// if adjacent country is in the continent subgraph
			if((*it)->getContinent() == continentObject) {
				if ((*it)->getVisited() != true) {
					//set the country visited that is pushed in the queue
					(*it)->setVisited(true);
					queue.push(*it);
				}		
			}
		}
		for (auto& country : worldMap) {
			//check for all countries that have the continent object
			if (country.second->getContinent() == continentObject) {
				Country *ptr = country.second;
				// check that those countries have been visited
				if (!ptr->getVisited()) {
					return false;
				}
			}
		}
	return true;
}
}