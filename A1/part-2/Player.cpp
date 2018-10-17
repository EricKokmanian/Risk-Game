#include <iostream>

using namespace std;

#include "Player.h"

Player::Player() {
	name = "";
}

Player::Player(string playerName) {
	name = playerName;
}

string Player::getPlayer() {
	return name;
}

void Player::setPlayer(string playerName) {
	name = playerName;
}