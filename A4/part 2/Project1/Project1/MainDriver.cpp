#include "GameEngine.h"
#include "Driver.h"
#include "Player.h"
#include "AttackPhase.h"
#include "FortificationPhase.h"
#include "Map.h"
#include "ConcreteStrategy1.h"
#include "ConcreteStrategy2.h"
#include "ConcreteStrategy3.h"
#include "Strategy.h"

int main() {
	// Setting up players and vector of players
	vector<Player*> players;
	Player David("David");
	Player John("John");

	//create countries
	Country Canada("Canada");
	Country USA("USA");
	Country Mexico("Mexico");
	Country France("France");
	Country Italy("Italy");

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
	Italy.addAdjacentCountry(&Italy);


	//add countries to david
	David.addCountry(&Canada);
	David.addCountry(&USA);
	Canada.setOwner(&David);
	Canada.setArmyNumber(10);
	USA.setOwner(&David);
	USA.setArmyNumber(6);

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

	// Real start
	int mode; 
	int maps;
	vector<string> names;
	string name;
	int playah;
	int games;
	int turn;

	cout << "WELCOME TO THE WORLD REKNOWN GAME RISK" << endl;
	cout << "Please select the mode you wish to play:" << endl << "1 - Single mode" << endl << "2 - Tournament Mode" << endl;
	cin >> mode;

	if (mode == 1) {
		cout << "Welcome to single mode" << endl;
	}
	else {
		cout << "Welcome to tournament mode" << endl;
		cout << "--------------------------" << endl;
		cout << "Please select the number of maps (1-5) you wish to play on : " << endl;
		cin >> maps;
		cout << "Don't forget to add the relevant map files to the map directory..." << endl;
		cout << "Now please enter the number of players (2-4) you wish to have in the tournament game :" << endl;
		cin >> playah;
		cout << "Enter the number of games (1-5) you wish to play :" << endl;
		cin >> games;
		cout << "Enter the number of turns (10-50) you want to have before declaring a draw : " << endl;
		cin >> turn;

		for (int i = 0; i < playah; i++) {
			cout << "Please enter the name of Player " << i << " : " << endl;
			cin >> name;
			names.push_back(name);
		}

		if (playah == 2) {
			Player* p1 = new Player(names.at(0));
			Player* p2 = new Player(names.at(1));
			players.push_back(p1);
			players.push_back(p2);
		}
		else if (playah == 3) {
			Player* p1 = new Player(names.at(0));
			Player* p2 = new Player(names.at(1));
			Player* p3 = new Player(names.at(2));
			players.push_back(p1);
			players.push_back(p2);
			players.push_back(p3);
		}
		else {
			Player* p1 = new Player(names.at(0));
			Player* p2 = new Player(names.at(1));
			Player* p3 = new Player(names.at(2));
			Player* p4 = new Player(names.at(3));
			players.push_back(p1);
			players.push_back(p2);
			players.push_back(p3);
			players.push_back(p4);
		}
		
		for (auto it = players.begin(); it != players.end(); ++it) {
			cout << "Player name : " << (*it)->getName() << endl;
		}
	}

	Driver d;
	AttackPhase attackP;
	FortificationPhase fortificationP;

	while (true) {
		for (Player* p : players) {

			// ASK PLAYER WHICH STARTEGY HE/SHE WANTS TO USE
			string strat;
			cout << "What strategy do you wish to adopt (ie. Aggressive, Passive, Random, Custom): " << endl;
			cin >> strat;

			if (strat == "Aggressive" || strat == "aggressive") {
				ConcreteStrategy1* cs1 = new ConcreteStrategy1();
				p->setStrategy(cs1);
				cout << "Agressive strategy adopted" << endl;
				p->executeReinforce(&worldMap, p);
				p->executeAttack(p);
				p->executeFortify(p);
				delete cs1;
				//delete dynamic pointers
			}
			else if (strat == "Passive" || strat == "passive") {
				ConcreteStrategy2* cs2 = new ConcreteStrategy2();
				p->setStrategy(cs2);
				cout << "PAssive strategy adopted" << endl;
				p->executeReinforce(&worldMap, p);
				p->executeAttack(p);
				p->executeFortify(p);
				delete cs2;
			}
			else if (strat == "Random" || strat == "random") {
				ConcreteStrategy3 cs3;
				p->setStrategy(&cs3);
				cout << "Random strategy adopted" << endl;
				p->executeReinforce(&worldMap, p);
				p->executeAttack(p);
				p->executeFortify(p);
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
