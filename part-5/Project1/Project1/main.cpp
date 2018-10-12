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
	cout << "Number of Countries: " << map.getNumberCountries() << endl;
	cout << "Number of Cards: " << deck.getNumberOfCards() << endl;

	system("pause");
	return 0;
}