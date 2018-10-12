#pragma once
#include <iostream>
#include <vector>
#include "Hand.h"
#include "Dice.h"
#include "Continent.h"
#include "Country.h"
#include "Card.h"

using namespace std;

class Player {

public:
	//instantiate Player in different ways
	Player();
	Player(string name);
	Player(int id, string name);
	void addDice(Dice* dice);
	Dice* getDice() { return dice; }
	//add countries inside "countries" vector
	void addCountry(Country* country);
	int getNumberOfArmy() { return numberOfArmy; }
	void setNumberOfArmy(int numberArmy) { numberOfArmy = numberArmy; }
	string getCountries();
	vector<Continent*> getContinents() { return continents; }
	void setHand(Hand* h);
	string getHand();
	string getName() { return name;}
	void setPlayerName(string name);
	void addContinent(Continent* continent);
	//empty methods
	void reinforce() {};
	void attack() {};
	void fortify() {};


public:
	string name;
	vector<Country*> countries;
	vector<Continent*> continents;
	int numberOfArmy;
	int id;
	Hand* hand;
	Dice* dice;

};