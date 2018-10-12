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

int Hand::exchange() {
	unordered_map<string, int> sortedCards;
	for (auto it = cards.begin(); it != cards.end(); ++it) {
		sortedCards[(*it)->getType()]++;
	}
	for (auto it = sortedCards.begin(); it != sortedCards.end(); ++it) {
		if ((*it).second >= 3) {
			
			return calculateExchangedArmySize();
		}
	}
}

void Hand::exchange3Cards(string cardType) {
	int count = 3;
	while (count != 0) {
		for (auto it = cards.begin(); it != cards.end(); ++it) {
			
			
		}
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
		return (exchangeTimes - 5) * 5;
	}
}
