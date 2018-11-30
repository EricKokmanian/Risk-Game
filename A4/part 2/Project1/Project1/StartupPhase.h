#pragma once

#include <vector>
#include <unordered_map>
#include "Continent.h"
#include "Country.h"
#include "Map.h"
#include "Player.h"


using namespace std;

class StartupPhase {
public:
	StartupPhase();
	StartupPhase(vector <Player*> order);
	void assignCountries(unordered_map<string, Country*> worldMap, vector <Player*> order);
	vector<Player*> orderOfPlay(vector <Player*> players);

	void provideArmy(vector<Player*> players);
	void placeArmy(int n, vector<Player*> players, unordered_map<string, Country*>);
	bool checkVisited(unordered_map<string, Country*>);

private:
	vector<Player*> order;
	vector<Country*> countries;

};
