#include <iostream>
using namespace std;

#include "Player.h"

Player::Player() {
	name = "";
}

Player::Player(string playerName) {
	name = playerName;
}

string Player::getPlayerName() {
	return name;
}

void Player::setPlayerName(string playerName) {
	name = playerName;
}