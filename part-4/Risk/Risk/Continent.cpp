#include <iostream>
#include <string>
using namespace std;
#include "Continent.h"

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
