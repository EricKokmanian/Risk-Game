#include <iostream>
#include <string>
#include "Card.h"
#include "Hand.h"
#include "Map.h"
#include "Country.h"
#include "Deck.h"

using namespace std;

int main() {
	Map map;
	Continent NorthAmerica;

	Country Canada, USA, Mexico, Greenland, France, Italy, Chili, China, Japan, Turkey;
	map.addCountry("Canada", &Canada);
	map.addCountry("USA", &USA);
	map.addCountry("Mexico", &Mexico);
	map.addCountry("Greenland", &Greenland);
	map.addCountry("France", &France);
	map.addCountry("Italy", &Italy);
	map.addCountry("Chili", &Chili);
	map.addCountry("China", &China);
	map.addCountry("Japan", &Japan);
	map.addCountry("Turkey", &Turkey);

	Deck deck(map.getNumberCountries());
	deck.printCards();
	cout << "\nNumber of Countries: " << map.getNumberCountries() << endl;
	cout << "Number of Cards: " << deck.getNumberOfCards() << endl;

	Hand hand1;
	Hand hand2;

	for (int i = 0; i < 3; i++) {
		deck.draw(hand1);
		deck.draw(hand2);
	}

	cout << "\nCards of hand1: ";
	for (auto it = hand1.getCards().begin(); it != hand1.getCards().end(); ++it) {
		cout << (*it)->getType() << ", ";
	}
	cout << "\nCards of hand2: ";
	for (auto it = hand2.getCards().begin(); it != hand2.getCards().end(); ++it) {
		cout << (*it)->getType() << ", ";
	}


	cout << "\nRemaining Cards in the deck: \n";
	deck.printCards();

	

	cout << hand1.exchange(deck);

	system("pause");
	return 0;
}