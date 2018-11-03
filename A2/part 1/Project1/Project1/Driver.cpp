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

	cout << "Welcome to the world reknown RISK Game !" << endl;
	cout << "----------------------------------------" << endl;
	cout << "First, let's being by selecting which map file to use..."<< endl;
	cout << "Please first start by copying your .map files in the 'Map Files' directory. \n" << endl;
	cout << "Now please enter the complete name of the file you wish to play on..." << endl;
	cin >> mapname;
	
	MapManager mm;
	mm.verifyMap(mapname);

	cout << "Your map file looks good!" << endl;
	cout << "Now, please enter the number of players you wish to have (2-6): " << endl;
	cin >> nbrPlayers;


}