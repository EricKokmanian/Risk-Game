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
	void addCountry(vector<Country*> country);
	void deleteCountry(Country* country);
	int getNumberOfArmy() { return numberOfArmy; }
	void setNumberOfArmy(int numberArmy) { numberOfArmy = numberArmy; }
	vector<Country*> getCountries() { return countries; }
	vector<Continent*> getContinents() { return continents; }
	void addToHand(Card* card);
	vector<Card*> getHand();
	string getName() { return name;}
	void setPlayerName(string name);
	void addContinent(Continent* continent);
	void removeContinent(Continent* continent);


public:
	string name;
	vector<Country*> countries;
	vector<Continent*> continents;
	int numberOfArmy;
	int id;
	Hand* hand;
	Dice* dice;

};