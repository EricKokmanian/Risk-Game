#include <iostream>
using namespace std;
#include "Player.h"


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

void Player::addCountry(vector<Country*> country)
{
	countries = country;
}

void Player::deleteCountry(Country *)
{
	//must implement
}

void Player::addToHand(Card * card)
{
	hand->addCard(card);
}

vector<Card*> Player::getHand()
{
	return hand->getCards();
}

void Player::addContinent(Continent* continent)
{
	continents.push_back(continent);
}

void Player::removeContinent(Continent* continent)
{
	//must implement
}

void Player::setPlayerName(string playerName) {
	name = playerName;
}

