#include "Map.h"
#include "Continent.h"
#include "Country.h"
#include "Player.h"
#include "Dice.h"
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include "MapManager.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	string mapname = "";
	int nbrPlayers = 0;
	Player* playerPtr = NULL;
	vector<Player*> players;
	Dice* dicePtr = NULL;
	Deck* deck = NULL;
	Hand* handPtr = NULL;
	Map* worldMap = NULL;

	cout << "Welcome to the world reknown RISK Game !" << endl;
	cout << "----------------------------------------" << endl;
	cout << "First, let's being by selecting which map file to use..."<< endl;
	cout << "Please first start by copying your .map files in the 'Map Files' directory. \n" << endl;
	cout << "Now please enter the complete name of the file you wish to play on..." << endl;
	cin >> mapname;
	
	// Verify validity of map file
	MapManager mm;
	worldMap = mm.verifyMap(mapname);

	cout << "Your map file looks good!" << endl;
	cout << "Now, please enter the number of players you wish to have (2-6): " << endl;
	cin >> nbrPlayers;

	// Creating number of players and adding to vector of players
	for (int i = 0; i < nbrPlayers; i++) {
		playerPtr = new Player("Player #" + i);
		players.push_back(playerPtr);
	}
	cout << nbrPlayers << " players have been created successfully. \n" << endl;

	// Creating a deck with as much cards as countries in the map
	deck = new Deck(worldMap->getSize());
	cout << "A deck of " << worldMap->getSize() << " cards have been created!\n" << endl;

	// Adding a dice and an empty hand to every player
	for (Player* plyr : players)
	{
		dicePtr = new Dice();
		handPtr = new Hand();
		plyr->addDice(dicePtr);
		plyr->setHand(handPtr);
	}
	
	system("pause");
}