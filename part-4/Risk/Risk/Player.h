#pragma once
#include <iostream>
#include <vector>
#include "Hand.h"
#include "Dice.h"
#include "Continent.h"

class Country;
using namespace std;

class Player {
public:
	Player();
	Player(string name);
	Player(int id, string name);
	void addDice(Dice* dice);
	Dice* getDice() { return dice; }
	void addCountry(Country* country);
	int getNumberOfArmy() { return numberOfArmy; }
	void setNumberOfArmy(int numberArmy) { numberOfArmy = numberArmy; }
	vector<Country*> getCountries() { return countries; }
	vector<Continent*> getContinents() { return continents; }
	void setHand(Hand* h);
	string getHand();
	string getName() { return name;}
	void setPlayerName(string name);
	void addContinent(Continent* continent);


public:
	string name;
	vector<Country*> countries;
	vector<Continent*> continents;
	int numberOfArmy;
	int id;
	Hand* hand;
	Dice* dice;

};