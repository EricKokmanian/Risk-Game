#include <iostream>
using namespace std;
#include "Player.h"
#include <sstream>


Player::Player()
{
	name = "";
	numberOfArmy = 0;
	dice = new Dice();
}

Player::Player(string playerName)
{
	name = playerName;
	dice = new Dice();

}

void Player::addDice(Dice* newDice)
{
	dice = newDice;
}

void Player::addCountry(Country* country)
{
	countries.push_back(country);
}

vector<Country*>& Player::getCountries() {
	return countries;
}

//string Player::getCountries()
//{
//	stringstream ss;
//	for (size_t i = 0; i < countries.size(); ++i)
//	{
//		if (i != 0)
//			ss << ",";
//		ss << countries[i]->getCountryName();
//	}
//	string s = ss.str();
//	return s;


void Player::addContinent(Continent* continent)
{
	continents.push_back(continent);
}

void Player::setPlayerName(string playerName) {
	name = playerName;
}

string Player::getPlayerName() {
	return name;
}
