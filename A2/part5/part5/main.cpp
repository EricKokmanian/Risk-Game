#include <iostream>
#include <string>
#include "AttackPhase.h"

using namespace std;

int main() {
	Map worldMap;
	Player Bob;
	Bob.setPlayerName("Bob");
	Player Alice;
	Alice.setPlayerName("Alice");
	Continent NorthAmerica, Europe;
	Country Canada("Canada", &NorthAmerica), USA("USA", &NorthAmerica), Mexico("Mexico", &NorthAmerica);
	Country France("France", &Europe), Italy("Italy", &Europe);
	worldMap.addCountry("Canada", &Canada);
	worldMap.addCountry("USA", &USA);
	worldMap.addCountry("Mexico", &Mexico);
	worldMap.addCountry("France", &France);
	worldMap.addCountry("Italy", &Italy);

	Canada.addAdjacentCountry(&USA);
	Canada.addAdjacentCountry(&France);
	USA.addAdjacentCountry(&Canada);
	USA.addAdjacentCountry(&Mexico);
	Mexico.addAdjacentCountry(&USA);
	France.addAdjacentCountry(&Canada);
	France.addAdjacentCountry(&Italy);
	Italy.addAdjacentCountry(&France);

	Canada.setOwner(&Bob);
	Italy.setOwner(&Bob);
	USA.setOwner(&Bob);
	Mexico.setOwner(&Alice);
	France.setOwner(&Alice);

	Bob.addCountry(&Canada);
	Bob.addCountry(&Italy);
	Bob.addCountry(&USA);
	Alice.addCountry(&Mexico);
	Alice.addCountry(&France);

	Canada.setArmyNumber(5);
	USA.setArmyNumber(3);
	Mexico.setArmyNumber(2);
	Italy.setArmyNumber(4);
	France.setArmyNumber(3);

	GameEngine gameEngine;
	// gameEngine.declareAttack(&Bob);

	AttackPhase attackPhase;
	attackPhase.setPlayer(&Bob);
	attackPhase.attack();

	system("pause");
}