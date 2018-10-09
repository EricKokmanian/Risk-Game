#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

#include "Country.h"

class Map {
	
	public :
		Map();
		void addCountry(string countryName, Country* countryPtr);
		//bool ifConnected();
		//bool ifConnectedCont(Continent* continent);
		
	private :
	unordered_map<string, Country*) worldMap;
}