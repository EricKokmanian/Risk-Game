#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Deck.h"

using namespace std;

Deck::Deck() {

}

Deck::Deck(int numOfCountries) {
	for (int i = 0; i < numOfCountries; i++) {
		cardDeck.push_back(new Card(i));
	}
}

Deck::~Deck() {
	for (auto it = cardDeck.begin(); it != cardDeck.end(); ++it) {
		delete (*it);
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

void Deck::draw(Hand& playerHand) {
	// randomly choose a card from the deck
	srand(time(NULL));
	int index = rand() % getNumberOfCards();
	// add card to player's hand
	playerHand.addCardToHand(cardDeck[index]);
	// remove the card at that index from the deck
	cardDeck.erase(cardDeck.begin() + index);
}

void Deck::addCardToDeck(Card* card) {
	cardDeck.push_back(card);
}