#include <iostream>
using namespace std;
#include "Player.h"

int main() {
	
	return 0;
}

Player::Player()
{
	id = 1;
	name = "";
	numberOfArmy = 0;
}

Player::Player(int id, string name)
{
	this->id = id;
	this->name = name;
	numberOfArmy = 0;
}

void Player::addCountry(Country *)
{
	//must implement
}

void Player::deleteCountry(Country *)
{
	//must implement
}

Hand Player::getHand()
{
	return Hand();
}

void Player::addContinent(Continent *)
{
	//must implement
}

void Player::removeContinent(Continent *)
{
	//must implement
}

void Player::setPlayerName(string playerName) {
	name = playerName;
}

