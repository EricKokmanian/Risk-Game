#pragma once

#include <vector>
#include "Continent.h"
#include "Country.h"
#include "Map.h"
#include "Player.h"


using namespace std;

class startupPhase {
public:
	startupPhase();
	startupPhase(vector <Player*> order);
	void assignCountries(vector <Country*> countries, vector <Player*> order);
	vector<Player*> orderOfPlay(vector <Player*> players);

	void provideArmy(vector<Player*> players);
	void placeArmy(int n, vector<Player*> players, vector<Country*>);
	bool checkVisited(vector<Country*>);

private:
	vector<Player*> order;
	vector<Country*> countries;

};