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

	Country Canada, USA, Mexico, Greenland, France, Italy, Chili, China, Japan, Turkey, Vietnam, Iceland;
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
	map.addCountry("Vietnam", &Vietnam);
	map.addCountry("Iceland", &Iceland);

	Deck deck(map.getNumberCountries());
	deck.printCards();
	cout << "\nNumber of Countries: " << map.getNumberCountries() << endl;
	cout << "Number of Cards: " << deck.getNumberOfCards() << endl;

	Hand hand1;
	Hand hand2;

	for (int i = 0; i < 5; i++) {
		deck.draw(hand1);
		deck.draw(hand2);
	}

	cout << "\nRemaining Cards in the deck: \n";
	deck.printCards();

	cout << "\nCards of hand1: ";
	for (auto it = hand1.getCards().begin(); it != hand1.getCards().end(); ++it) {
		cout << (*it)->getType() << ", ";
	}
	cout << "\nCards of hand2: ";
	for (auto it = hand2.getCards().begin(); it != hand2.getCards().end(); ++it) {
		cout << (*it)->getType() << ", ";
	}
	
	//exchange 1
	cout << "\nHand1 can exchange his cards for: " << hand1.exchange(deck) << endl;
	//exchange 2
	cout << "Hand2 can exchange his cards for: " << hand2.exchange(deck) << endl;

	cout << "\nRemaining Cards in the deck: \n";
	deck.printCards();

	for (int i = 0; i < 8; i++) {
		deck.draw(hand1);
	}
	//exchange 3
	hand1.exchange(deck);
	for (int i = 0; i < 3; i++) {
		deck.draw(hand1);
	}
	//exchange 4
	hand1.exchange(deck);
	for (int i = 0; i < 3; i++) {
		deck.draw(hand1);
	}
	//exchange 5
	hand1.exchange(deck);
	for (int i = 0; i < 3; i++) {
		deck.draw(hand1);
	}
	//exchange 6
	hand1.exchange(deck);
	for (int i = 0; i < 3; i++) {
		deck.draw(hand1);
	}
	//exchange 7
	hand1.exchange(deck);
	for (int i = 0; i < 3; i++) {
		deck.draw(hand1);
	}

	//exchange 8
	cout << "\nAfter 8 exchanges, hand1 can exchange his cards for: " << hand1.exchange(deck) << endl;


	system("pause");
	return 0;
}