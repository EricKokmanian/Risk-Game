#include <iostream>
#include <string>
#include "GameEngine.h"

using namespace std;

GameEngine::GameEngine() {

}

void GameEngine::addPlayer(Player* player) {
	players.push_back(player);
}

void GameEngine::declareAttack(Player* player) {
	string attackDeclaration;
	cout << player->getName() << ", do you want to attack a player? (yes or no)" << endl;
	cin >> attackDeclaration;

	if (attackDeclaration == "yes") {
		AttackPhase attackPhase;
		attackPhase.setPlayer(player);
		attackPhase.attack();
	}
}
//{
   //cout << "Please enter a valid player name: " << endl;
   //for (auto it = players.begin(); it != players.end(); ++it) {
   //	cout << (*it)->getPlayerName() << endl;
   //}
//}
