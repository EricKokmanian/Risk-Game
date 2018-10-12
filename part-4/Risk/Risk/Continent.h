#pragma once
#include <iostream>	
#include <string>

using namespace std;

class Continent {

public:
	Continent();
	Continent(string continentName);
	string getContinentName();
	void setContinentName(string continentName);

private:
	string name;

};