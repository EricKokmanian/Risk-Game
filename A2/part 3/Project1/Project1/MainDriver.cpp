#include "GameEngine.h"
#include "Driver.h"
#include "Player.h"
#include "AttackPhase.h"
#include "FortificationPhase.h"
#include "Map.h"

void main() {
	vector<Player*> players;
	Player David("David");
	Player John("John");
	players.push_back(&David);
	players.push_back(&John);


	//create countries
	Country Canada("Canada");
	Country USA("USA");
	Country Mexico("Mexico");
	Country France("France");

	//create maps and assign countries to map
	Map worldMap;
	worldMap.addCountry("Canada", &Canada);
	worldMap.addCountry("USA", &USA);
	worldMap.addCountry("Mexico", &Mexico);
	worldMap.addCountry("France", &France);

	//add countries to david
	David.addCountry(&Canada);
	David.addCountry(&USA);
	David.addCountry(&Mexico);
	Canada.setOwner(&David);
	Canada.setArmyNumber(3);
	USA.setOwner(&David);
	USA.setArmyNumber(2);
	Mexico.setOwner(&David);
	Mexico.setArmyNumber(1);

	//add countries to John
	France.setOwner(&John);
	John.addCountry(&France);
	France.setArmyNumber(1);

	Driver d;

	//reinforce method for player David while having a few countries in possession
	//d.reinforce(worldMap, David);

	Hand h1;
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	David.setHand(&h1);

	//reinforce by trading cards
	//d.reinforce3(worldMap, David);

	system("pause");
	AttackPhase attackP;
	FortificationPhase fortificationP;

	for (Player* p : players) {
		while (worldMap.isWinner(p) != true) {
		
			// call reinforcement phase

			
			// call attack phase
			attackP.setPlayer(p);
			attackP.attack();

			// call fortification phase
			fortificationP.setPlayer(p);
			fortificationP.moveArmy();
			
		}
	}
	
}