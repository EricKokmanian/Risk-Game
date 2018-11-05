#include "GameEngine.h"
#include "Driver.h"
#include "Player.h"
#include "AttackPhase.h"
#include "FortificationPhase.h"
#include "Map.h"

void main() {
	// Setting up players and vector of players
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
	Canada.addAdjacentCountry(&USA);
	Canada.addAdjacentCountry(&France);
	USA.addAdjacentCountry(&Canada);
	USA.addAdjacentCountry(&Mexico);
	Mexico.addAdjacentCountry(&USA);
	France.addAdjacentCountry(&Canada);


	//add countries to david
	David.addCountry(&Canada);
	David.addCountry(&USA);
	David.addCountry(&Mexico);
	Canada.setOwner(&David);
	Canada.setArmyNumber(3);
	USA.setOwner(&David);
	USA.setArmyNumber(3);
	Mexico.setOwner(&David);
	Mexico.setArmyNumber(3);


	//add countries to John
	France.setOwner(&John);
	John.addCountry(&France);
	France.setArmyNumber(1);

	Driver d;
	AttackPhase attackP;
	FortificationPhase fortificationP;


	for (Player* p : players) {
		while (worldMap.isWinner(p) != true) {
		
			// call reinforcement phase
			d.reinforce(worldMap, *p);
			
			// call attack phase
			attackP.setPlayer(p);
			attackP.attack();

			// call fortification phase
			fortificationP.setPlayer(p);
			fortificationP.moveArmy();
			
		}
		cout << "---------------" << endl;
		cout << "CONGRATULATIONS" << endl;
		cout << "---------------" << endl;
		cout << "--> Player " << p->getName() << " has WON! <--" << endl;
		break;
	}
	system("pause");
}