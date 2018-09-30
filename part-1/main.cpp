#include <iostream>
#include <string>

using namespace std;
#include "Country.h"
#include "Player.h"
#include "Map.h"

int main() {

	Map worldMap;

	Player John("John");
	Player Tony("Tony");

	Country Canada;
	Country USA;
	Country Mexico;
	Continent NorthAmerica;

	NorthAmerica.setContinentName("North America");

	Canada.setCountryName("Canada");
	Canada.setOwner(&John);
	Canada.setArmyNumber(5);
	Canada.setContinent(&NorthAmerica);
	Canada.addAdjacentCountry(&USA);
	Canada.addAdjacentCountry(&Mexico);
	USA.setCountryName("USA");
	USA.setContinent(&NorthAmerica);
	USA.addAdjacentCountry(&Canada);
	USA.addAdjacentCountry(&Mexico);
	Mexico.setCountryName("Mexico");
	Mexico.setContinent(&NorthAmerica);
	Mexico.addAdjacentCountry(&Canada);
	Mexico.addAdjacentCountry(&USA);

	worldMap.addCountry("Canada", &Canada);
	worldMap.addCountry("USA", &USA);
	worldMap.addCountry("Mexico", &Mexico);

	cout << Canada.getCountryName() << " in "<< Canada.getContinent()->getContinentName() << " belongs to " << Canada.getOwner()->getPlayerName() <<
		" and has an army of " << Canada.getArmyNumber() << endl;

	cout << "Canada's adjacent countries are: ";
	Canada.printAdjacentCountry();

	system("pause");
}