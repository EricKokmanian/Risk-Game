#include <iostream>	
#include "Map.h"
#include "Player.h"
#include "Country.h"
#include "Continent.h"
#include "FortificationPhase.h"

int main() {
	Map worldMap;
	Player Bob;
	Bob.setPlayerName("Bob");
	Player Alice;
	Alice.setPlayerName("Alice");
	Continent NorthAmerica, Europe;
	Country Canada("Canada", &NorthAmerica), USA("USA", &NorthAmerica), Mexico("Mexico", &NorthAmerica);
	Country France("France", &Europe), Italy("Italy", &Europe), Germany("Germany", &Europe);
	worldMap.addCountry("Canada", &Canada);
	worldMap.addCountry("USA", &USA);
	worldMap.addCountry("Mexico", &Mexico);
	worldMap.addCountry("France", &France);
	worldMap.addCountry("Italy", &Italy);
	worldMap.addCountry("Germany", &Germany);

	Canada.addAdjacentCountry(&USA);
	Canada.addAdjacentCountry(&France);
	USA.addAdjacentCountry(&Canada);
	USA.addAdjacentCountry(&Mexico);
	Mexico.addAdjacentCountry(&USA);
	France.addAdjacentCountry(&Canada);
	France.addAdjacentCountry(&Italy);
	France.addAdjacentCountry(&Germany);
	Italy.addAdjacentCountry(&France);
	Germany.addAdjacentCountry(&France);

	Canada.setOwner(&Bob);
	Italy.setOwner(&Bob);
	USA.setOwner(&Bob);
	Mexico.setOwner(&Alice);
	France.setOwner(&Alice);
	Germany.setOwner(&Alice);

	Bob.addCountry(&Canada);
	Bob.addCountry(&Italy);
	Bob.addCountry(&USA);
	Alice.addCountry(&Mexico);
	Alice.addCountry(&France);
	Alice.addCountry(&Germany);

	Canada.setArmyNumber(5);
	USA.setArmyNumber(3);
	Mexico.setArmyNumber(2);
	Italy.setArmyNumber(4);
	France.setArmyNumber(1);
	Germany.setArmyNumber(2);

	FortificationPhase fortificationPhase(&Bob);
	fortificationPhase.moveArmy();

	system("pause");

}
