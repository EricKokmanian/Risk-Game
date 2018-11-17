#include <iostream>
using namespace std;
#include "Player.h"
#include "Country.h"
#include "Hand.h"
#include "Card.h"
#include <sstream>
#include "Map.h"
#include <algorithm>
#include <vector>


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
	countries_names.push_back(country->getCountryName());
}

void Player::removeCountry(Country* country) {
	countries.erase(remove(countries.begin(), countries.end(), country), countries.end());
}

vector<Country*>& Player::getCountries()
{
	return countries;


	/*for (auto it = countries.begin(); it != countries.end(); ++it) {
		cout << (*it)->getCountryName() << ", " << end;
	}
	string s = ss.str();
	return s;*/
}

string Player::getCountries(int i)
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
}

void Player::setHand(Hand* h)
{
	hand = h;
}

Hand& Player::getHand()
{
	return *hand;
}

void Player::addContinent(Continent continent)
{
	continents.push_back(continent);
}

int Player::exchange()
{
	int armies = 0;
	int infantry = 0;
	int cavalry = 0;
	int artillery = 0;
	for (int x = 0;x < getHand().cards.size();x++) {
		if (getHand().cards[x].getType() == "Infantry") {
			infantry++;
		}
		else if (getHand().cards[x].getType() == "Cavalry") {
			cavalry++;
		}
		else if (getHand().cards[x].getType() == "Artillery") {
			artillery++;
		}
	}

	bool done = false;

	if (getHand().cards.size() > 5) {
		cout << "You have more than 5 cards. Please trade a set." << endl;
	}
	if (infantry >= 3) {
		string answer;
		cout << "You have at least 3 Infantry cards. Do you wish to trade 3 cards for armies? (yes or no)" << endl;
		cin >> answer;
		if (answer == "yes") {
			int a = 0;
			for (size_t i = 0; i < getHand().cards.size(); )
			{
				if (getHand().cards[i].getType() == "Infantry" && a < 4)
				{
					getHand().cards.erase(getHand().cards.begin() + i);
				}
				else
				{
					i++;
				}
			}
			done = true;
			armies = 3;
		}
	}
	if (cavalry >= 3 && !done) {
		string answer;
		cout << "You have at least 3 Cavalry cards. Do you wish to trade 3 cards for armies? (yes or no)" << endl;
		cin >> answer;
		if (answer == "yes") {
			int a = 0;
			for (size_t i = 0; i < getHand().cards.size(); )
			{
				if (getHand().cards[i].getType() == "Cavalry" && a < 4)
				{
					getHand().cards.erase(getHand().cards.begin() + i);
				}
				else
				{
					i++;
				}
			}
			done = true;
			armies = 3;
		}
	}

	if (artillery >= 3 && !done) {
		string answer;
		cout << "You have at least 3 Artillery cards. Do you wish to trade 3 cards for armies? (yes or no)" << endl;
		cin >> answer;
		if (answer == "yes") {
			int a = 0;
			for (size_t i = 0; i < getHand().cards.size(); )
			{
				if (getHand().cards[i].getType() == "Artillery" && a < 4)
				{
					getHand().cards.erase(getHand().cards.begin() + i);
				}
				else
				{
					i++;
				}
			}
			done = true;
			armies = 3;
		}
	}

	if (artillery >= 1 && cavalry >= 1 && infantry >= 1 && !done) {
		string answer;
		cout << "You have at least 1 card of each type. Do you wish to trade 3 cards for armies? (yes or no)" << endl;
		cin >> answer;
		if (answer == "yes") {
			int a = 0;
			int b = 0;
			int c = 0;
			for (size_t i = 0; i < getHand().cards.size(); )
			{
				if (getHand().cards[i].getType() == "Artillery" && a < 1)
				{
					getHand().cards.erase(getHand().cards.begin() + i);
					a++;
				}
				if (getHand().cards[i].getType() == "Infantry" && b < 1)
				{
					getHand().cards.erase(getHand().cards.begin() + i);
					b++;
				}
				if (getHand().cards[i].getType() == "Cavalry" &&  c < 1)
				{
					getHand().cards.erase(getHand().cards.begin() + i);
					c++;
				}
				else
				{
					i++;
				}
			}
			done = true;
			armies = 3;
		}
	}
	return armies;
}

int Player::ifOwnContinent()
{
	int australia_value = 0;
	int continent_value = 0;
	if (find(countries_names.begin(), countries_names.end(), "New Guinea") != countries_names.end()) {
		australia_value += 1;
	}
	if (find(countries_names.begin(), countries_names.end(), "Eastern Australia") != countries_names.end()) {
		australia_value += 1;
	}
	if (find(countries_names.begin(), countries_names.end(), "Western Australia") != countries_names.end()) {
		australia_value += 1;
	}
	if (find(countries_names.begin(), countries_names.end(), "Indonesia") != countries_names.end()) {
		australia_value += 1;
	}
	if (australia_value == 4) {
		continent_value += 2;
	}
	return continent_value;
}

void Player::setPlayerName(string playerName) {
	name = playerName;
}

