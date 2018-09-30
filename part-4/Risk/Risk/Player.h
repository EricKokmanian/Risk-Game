#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include "Hand.h"
using namespace std;

class Country;
class Continent;

class Player {
public:
	Player();
	Player(int id, string name);
	void addCountry(Country*);
	void deleteCountry(Country*);
	int getNumberOfArmy() { return numberOfArmy; }
	void setNumberOfArmy(int numberArmy) { numberOfArmy = numberArmy; }
	vector<Country*> getCountries() { return countries; }
	void addToHand(Card* card) { hand.addCard(card); }
	Hand getHand();
	string getName() { return name;}
	void setPlayerName(string name);
	void addContinent(Continent*);
	void removeContinent(Continent*);


private:
	string name;
	vector<Country*> countries;
	vector<Continent*> continents;
	int numberOfArmy;
	int id;
	Hand hand;

};
#endif // PLAYER_H