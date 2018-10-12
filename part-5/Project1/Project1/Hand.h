#pragma once
#include <vector>
#include "Card.h"

using namespace std;

class Hand
{
public:
	Hand();
	~Hand();
	int exchange();
	void exchange3Cards(string);
	int calculateExchangedArmySize();


private:
	static int exchangeTimes;
	vector<Card*> cards;
};
