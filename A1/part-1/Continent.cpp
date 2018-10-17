#include <iostream>
#include <string>
#include "Continent.h"

using namespace std;


Continent::Continent() {
	name = "";
}

Continent::Continent(string continentName) {
	name = continentName;
}

string Continent::getContinentName() {
	return name;
}

void Continent::setContinentName(string continentName) {
	name = continentName;
}
