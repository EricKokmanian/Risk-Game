#include <iostream>
#include "Hand.h"
#include "Card.h"
#include <string>
#include <unordered_map>

using namespace std;

int Hand::exchangeTimes;

Hand::Hand() {

}

Hand::~Hand() {

}

vector<Card*>& Hand::getCards() {
	return cards;
}

int Hand::exchange(Deck& deck) {
	unordered_map<string, int> sortedCards;
	int count = 0;
	for (auto it = cards.begin(); it != cards.end(); ++it) {
		sortedCards[(*it)->getType()]++;
	}
	for (auto it = sortedCards.begin(); it != sortedCards.end(); ++it) {
		if ((*it).second >= 3) {
			exchange3Cards(deck, (*it).first);
			exchangeTimes++;
			return calculateExchangedArmySize();
		}
		else if ((*it).second != 0) {
			count++;
			if (count == 3) {
				exchangeDifferentCards(deck);
				exchangeTimes++;
				return calculateExchangedArmySize();
			}

		}
		else {
			return 0;
		}
	}
	return 0;
}

void Hand::exchange3Cards(Deck& deck, string cardType) {
	int count = 3;
	while (count != 0) {
		for (auto it = cards.begin(); it != cards.end(); ++it) {
			if ((*it)->getType() == cardType) {
				deck.addCardToDeck(*it);
				it = cards.erase(it);
				count--;
				break;
			}
		}
		for (auto it = cards.begin(); it != cards.end(); ++it) {
			if ((*it)->getType() == cardType) {
				deck.addCardToDeck(*it);
				it = cards.erase(it);
				count--;
				break;
			}
		}
		for (auto it = cards.begin(); it != cards.end(); ++it) {
			if ((*it)->getType() == cardType) {
				deck.addCardToDeck(*it);
				it = cards.erase(it);
				count--;
				break;
			}
		}
		break;
	}
}

void Hand::exchangeDifferentCards(Deck& deck) {
	bool infantry = false, cavalry = false, artillery = false;
	while (infantry != true && cavalry != true && artillery != true) {
		for (auto it = cards.begin(); it != cards.end(); ) {
			if ((*it)->getType() == "Infantry" && infantry != true) {
				deck.addCardToDeck(*it);
				it = cards.erase(it);
			}
			else if ((*it)->getType() == "Cavalry" && cavalry != true) {
				deck.addCardToDeck(*it);
				it = cards.erase(it);
			}
			else if ((*it)->getType() == "Artillery" && artillery != true) {
				deck.addCardToDeck(*it);
				it = cards.erase(it);
			}

		}
		break;
	}
}

int Hand::calculateExchangedArmySize() {
	int totalArmySize = 0;
	// return 5,6,7,8,9,10
	if (exchangeTimes < 7) {
		return 4 + exchangeTimes;
	}
	// return 15,20,25,30...
	else {
		return (exchangeTimes - 4) * 5;
	}
}

void Hand::addCardToHand(Card* card) {
	cards.push_back(card);
}
