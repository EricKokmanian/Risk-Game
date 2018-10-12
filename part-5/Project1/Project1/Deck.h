#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class Deck {
	public:
		Deck();
		Deck(int);
		vector<Card*>& getCards();
		int getNumberOfCards();
		void printCards();
		Card* draw();

	private:
		vector<Card*> cardDeck;
};
