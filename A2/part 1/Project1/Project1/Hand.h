#pragma once
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

class Deck;

class Hand
{
public:
	Hand();
	~Hand();
	int exchange(Deck&);
	void exchange3Cards(Deck&, string);
	void exchangeDifferentCards(Deck&);
	int calculateExchangedArmySize();
	void addCardToHand(Card*);
	vector<Card*>& getCards();
	vector<Card*> cards;

private:
	static int exchangeTimes;
	
};

