#include <iostream>
#include <string>

using namespace std;

#include "Continent.h"

Continent::Continent() {
	name = "";
}

Continent::Continent(string contName) {
	name = contName;
}

string Continent::getContName() {
	return name;
}

void Continent::setContName(string contName) {
	name = contName;
}