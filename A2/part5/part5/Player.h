#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Dice.h"
#include "Continent.h"
#include "Country.h"

using namespace std;

class Country;
class Player {
public:
	Player();
	Player(string name);
	~Player();
	void addDice(Dice* dice);
	Dice* getDice() { return dice; }
	void addCountry(Country* country);
	int getNumberOfArmy() { return numberOfArmy; }
	void setNumberOfArmy(int numberArmy) { numberOfArmy = numberArmy; }
	vector<Country*>& getCountries();
	void removeCountry(Country* country);
	vector<Continent*> getContinents() { return continents; }
	string getName() { return name; }
	void setPlayerName(string name);
	string getPlayerName();
	void addContinent(Continent* continent);
	void reinforce() {};
	void attack() {};
	void fortify() {};

public:
	string name;
	vector<Country*> countries;
	vector<Continent*> continents;
	int numberOfArmy;
	Dice* dice;

};