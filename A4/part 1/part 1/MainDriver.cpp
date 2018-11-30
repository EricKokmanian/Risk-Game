#include "GameEngine.h"
#include "Driver.h"
#include "Player.h"
#include "AttackPhase.h"
#include "FortificationPhase.h"
#include "Map.h"
#include "ConcreteStrategy1.h"
#include "ConcreteStrategy2.h"
#include "ConcreteStrategy3.h"
#include "ConcreteStrategy4.h"
#include "Strategy.h"

int main() {
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
	Country Italy("Italy");
	Country Germany("Germany");
	Country Brazil("Brazil");

	//create maps and assign countries to map
	Map worldMap;
	worldMap.addCountry("Canada", &Canada);
	worldMap.addCountry("USA", &USA);
	worldMap.addCountry("Mexico", &Mexico);
	worldMap.addCountry("France", &France);
	worldMap.addCountry("Brazil", &Brazil);
	worldMap.addCountry("Germany", &Germany);
	Germany.addAdjacentCountry(&France);
	Brazil.addAdjacentCountry(&Mexico);
	Canada.addAdjacentCountry(&USA);
	Canada.addAdjacentCountry(&France);
	USA.addAdjacentCountry(&Canada);
	USA.addAdjacentCountry(&Mexico);
	Mexico.addAdjacentCountry(&USA);
	France.addAdjacentCountry(&Canada);
	Italy.addAdjacentCountry(&Italy);


	//add countries to david
	David.addCountry(&Canada);
	David.addCountry(&USA);
	Canada.setOwner(&David);
	Canada.setArmyNumber(10);
	USA.setOwner(&David);
	USA.setArmyNumber(6);
	Mexico.setOwner(&David);
	Mexico.setArmyNumber(1);

	Italy.setOwner(&David);
	David.addCountry(&Italy);
	Italy.setArmyNumber(3);


	//add countries to John
	France.setOwner(&John);
	John.addCountry(&France);
	France.setArmyNumber(1);
	John.addCountry(&Mexico);
	Mexico.setOwner(&John);
	Mexico.setArmyNumber(1);
	Germany.setOwner(&John);
	Brazil.setOwner(&John);
	John.addCountry(&Germany);
	John.addCountry(&Brazil);
	Germany.setArmyNumber(3);
	Brazil.setArmyNumber(4);


	Driver d;
	AttackPhase attackP;
	FortificationPhase fortificationP;

	while(true){
		for (Player* p : players) {

			// ASK PLAYER WHICH STARTEGY HE/SHE WANTS TO USE
			string strat;
			cout << "What strategy do you wish to adopt (ie. Aggressive, Passive, Random, Custom, Cheater): " << endl;
			cin >> strat;

			if (strat == "Aggressive" || strat == "aggressive") {
				ConcreteStrategy1* cs1 = new ConcreteStrategy1();
				p->setStrategy(cs1);
				cout << "Agressive strategy adopted" << endl;
				p->executeReinforce(&worldMap, p);
				p->executeAttack(p);
				p->executeFortify(worldMap,p);
				delete cs1;
				//delete dynamic pointers
			}
			else if (strat == "Passive" || strat == "passive") {
				ConcreteStrategy2* cs2 = new ConcreteStrategy2();
				p->setStrategy(cs2);
				cout << "PAssive strategy adopted" << endl;
				p->executeReinforce(&worldMap, p);
				p->executeAttack(p);
				p->executeFortify(worldMap,p);
				delete cs2;
			}
			else if (strat == "Random" || strat == "random") {
				ConcreteStrategy3 cs3;
				p->setStrategy(&cs3);
				cout << "Random strategy adopted" << endl;
				p->executeReinforce(&worldMap, p);
				p->executeAttack(p);
				p->executeFortify(worldMap,p);

			}
			else if (strat == "Cheater" || strat == "cheater") {
				ConcreteStrategy4 cs4;
				p->setStrategy(&cs4);
				cout << "Cheater strategy adopted" << endl;
				p->executeReinforce(&worldMap, p);
				p->executeAttack(p);
				p->executeFortify(worldMap, p);

			}

			else {
				// call reinforcement phase
				d.reinforce(worldMap, *p);

				// call attack phase
				attackP.setPlayer(p);
				attackP.attack();

				// call fortification phase
				fortificationP.setPlayer(p);
				fortificationP.moveArmy();
			}

		
			if (worldMap.isWinner(p) == true) {

				cout << "---------------" << endl;
				cout << "CONGRATULATIONS" << endl;
				cout << "---------------" << endl;
				cout << "--> Player " << p->getName() << " has WON! <--" << endl;
				break;
			}
		}
		system("pause");
	}
}
