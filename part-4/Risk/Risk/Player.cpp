#include <iostream>
using namespace std;
#include "Player.h"
#include <sstream>
#include "Hand.h"
#include "Card.h"


Player::Player()
{
	id = 1;
	name = "";
	numberOfArmy = 0;

}

Player::Player(string playerName)
{
	name = playerName;

}

Player::Player(int id, string name)
{
	this->id = id;
	this->name = name;
	numberOfArmy = 0;
}

void Player::addDice(Dice* newDice)
{
	dice = newDice;
}

void Player::addCountry(Country* country)
{
	countries.push_back(country);
}

//Get list of country names by converting the country vector into strings thanks to stringstream
string Player::getCountries()
{
	stringstream ss;
	for (size_t i = 0; i < countries.size(); ++i)
	{
		if (i != 0)
			ss << ",";
		ss << countries[i]->getCountryName();
	}
	string s = ss.str();
	return s;
	

	/*for (auto it = countries.begin(); it != countries.end(); ++it) {
		cout << (*it)->getCountryName() << ", " << end;
	}
	string s = ss.str();
	return s;*/
}

void Player::setHand(Hand* h)
{
	hand = h;
}

//convert cards in hand into a list of strings
string Player::getHand()
{
	stringstream ss;
	for (size_t i = 0; i < hand->cards.size(); ++i)
	{
		if (i != 0)
			ss << ",";
		ss << hand->cards[i]->getType();
	}
	string s = ss.str();
	return s;
}

void Player::addContinent(Continent* continent)
{
	continents.push_back(continent);
}

void Player::setPlayerName(string playerName) {
	name = playerName;
}

