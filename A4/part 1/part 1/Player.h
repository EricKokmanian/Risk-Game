#pragma once
#include <iostream>
#include <vector>
#include "Hand.h"
#include "Dice.h"
#include "Continent.h"
#include "Strategy.h"
#include <unordered_map>
#include "Map.h"

class Country;
class Strategy;
class Map;

using namespace std;

class Player {
public:
	Player();
	Player(string name);
	Player(int id, string name);
	void addDice(Dice* dice);
	Dice* getDice() { return dice; }
	void addCountry(Country* country);
	void removeCountry(Country*);
	int getNumberOfArmy() { return numberOfArmy; }
	void setNumberOfArmy(int numberArmy) { numberOfArmy = numberArmy; }
	vector<Country*>& getCountries();
	string getCountries(int);
	vector<Continent> getContinents() { return continents; }
	void setHand(Hand* h);
	Hand& getHand();
	string getName() { return name; }
	int ifOwnContinent();
	void setPlayerName(string name);
	void addContinent(Continent continent);
	void attack() {};
	void fortify() {};
	int exchange();
	void setStrategy(Strategy*);
	Strategy* getStrategy();
	void executeReinforce(Map*, Player*);
	void executeAttack(Player*);
	void executeFortify(Map,Player*);


private:
	Strategy* strategy;
	string name;
	vector<Country*> countries;
	vector<string> countries_names;
	vector<Continent> continents;
	int numberOfArmy;
	int id;
	Hand* hand;
	Dice* dice;

};

