#include <iostream>
#include "Deck.h"

using namespace std;

Deck::Deck() {
	
}

Deck::Deck(int numOfCountries) {
	for (int i = 0; i < numOfCountries; i++) {
		cardDeck.push_back(new Card(i));
	}
}

vector<Card*>& Deck::getCards() {
	return cardDeck;
}

int Deck::getNumberOfCards() {
	return cardDeck.size();
}

void Deck::printCards() {
	for (auto it = cardDeck.begin(); it != cardDeck.end(); ++it) {
		cout << (*it)->getType() << endl;
	}
}

Card* Deck::draw() {
	// randomly choose a card from the deck
	int index = rand() % getNumberOfCards();
	Card* cardDrawn = cardDeck[index];
	// remove the card at that index from the deck
	cardDeck.erase(cardDeck.begin() + index);
	return cardDrawn;
}
