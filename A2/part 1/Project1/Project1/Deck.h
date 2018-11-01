#pragma once

#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"

class Hand;

class Deck {
public:
	Deck();
	Deck(int);
	vector<Card*>& getCards();
	int getNumberOfCards();
	void printCards();
	void draw(Hand&);
	void addCardToDeck(Card*);

private:
	vector<Card*> cardDeck;
};

