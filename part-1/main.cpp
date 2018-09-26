#include <iostream>
#include <string>

using namespace std;
#include "Country.h"
#include "Player.h"

int main() {

	Player John("John");
	Player Tony("Tony");

	Country Canada;
	Continent NorthAmerica;

	NorthAmerica.setContinentName("North America");

	Canada.setCountryName("Canada");
	Canada.setOwner(&John);
	Canada.setArmyNumber(5);
	Canada.setContinent(&NorthAmerica);


	cout << Canada.getCountryName() << " in "<< Canada.getContinent()->getContinentName() << " belongs to " << Canada.getOwner()->getPlayerName() <<
		" and has an army of " << Canada.getArmyNumber() << endl;

	system("pause");
}