#include "Driver.h"
#include "Player.h"
#include <sstream>
using namespace std;

Driver::Driver()
{
}


Driver::~Driver()
{
}

void Driver::start()
{
}

void Driver::reinforce(Map worldmap, Player player)
{
	int x = worldmap.getNumberOfCountries(player);
	if (x < 3) {
		x = 3;
	}

	string name;
	cout << "NUMBER OF COUNTRIES BY DAVID:" << x << endl;
	cout << "Here are the countries owned by David :" << player.getCountries(1) << endl << "You have " << x << " armies to place." << endl;
	for (int a = 0;a < x; a++) {
		cout << "Please enter a country from that list (case-sensitive) where you would like to place 1 army." << endl;
		cin >> name;
		worldmap.getCountry(name)->addArmy(1);
		cout << "NUMBER OF ARMIES OF " << worldmap.getCountry(name)->getCountryName() << " : " << worldmap.getCountry(name)->getArmyNumber() << endl;
	}

	cout << "-------- END OF REINFORCE 1 ---------" << endl;

}

void Driver::reinforce2(Map worldmap, Player player)
{
	int x = worldmap.getNumberOfCountries(player);
	if (x < 3) {
		x = 3;
	}
	x += player.ifOwnContinent();

	string name;
	cout << "NUMBER OF COUNTRIES BY JOHN:" << x << endl;
	cout << "Here are the countries owned by John :" << player.getCountries(1) << endl << "You have " << x << " armies to place." << endl;
	for (int a = 0;a < x; a++) {
		cout << "Please enter a country from that list (case-sensitive) where you would like to place 1 army." << endl;
		cin >> name;
		worldmap.getCountry(name)->addArmy(1);
		cout << "NUMBER OF ARMIES OF " << worldmap.getCountry(name)->getCountryName() << " : " << worldmap.getCountry(name)->getArmyNumber() << endl;
	}

	cout << "-------- END OF REINFORCE 2 ---------" << endl;


}

void Driver::reinforce3(Map worldmap, Player player)
{
	int armies = 0;
	vector<Card> cards = player.getHand().getCards();
	if (cards.size() > 5) {
		armies = player.exchange();
	}
	armies += 3;

	string name;
	cout << "NUMBER OF COUNTRIES BY DAVID:" << armies << endl;
	cout << "Here are the countries owned by David :" << player.getCountries(1) << endl << "You have " << armies << " armies to place." << endl;
	for (int a = 0;a < armies; a++) {
		cout << "Please enter a country from that list (case-sensitive) where you would like to place 1 army." << endl;
		cin >> name;
		worldmap.getCountry(name)->addArmy(1);
		cout << "NUMBER OF ARMIES OF " << worldmap.getCountry(name)->getCountryName() << " : " << worldmap.getCountry(name)->getArmyNumber() << endl;
	}

	cout << "-------- END OF REINFORCE 3 ---------" << endl;

}

void Driver::attack(Player* p)
{
}

void Driver::fortify(Player* p)
{
}
