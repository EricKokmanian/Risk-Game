#include <iostream>
#include <string>
#include "Country.h"
#include "Continent.h"
#include "Player.h"
#include "Map.h"

using namespace std;


int main() {

	Map worldMap;

	Player John("John");
	Player Tony("Tony");

	Country Canada;
	Country USA;
	Country Mexico;
	Country Greenland;

	Continent NorthAmerica;
	Continent Europe;

	NorthAmerica.setContinentName("North America");
	Europe.setContinentName("Europe");

	Canada.setCountryName("Canada");
	Canada.setOwner(&John);
	Canada.setArmyNumber(5);
	Canada.setContinent(&NorthAmerica);
	Canada.addAdjacentCountry(&USA);
	Canada.addAdjacentCountry(&Mexico);
	Canada.addAdjacentCountry(&Greenland);
	USA.setCountryName("USA");
	USA.setContinent(&NorthAmerica);
	USA.addAdjacentCountry(&Canada);
	USA.addAdjacentCountry(&Mexico);
	Mexico.setCountryName("Mexico");
	Mexico.setContinent(&NorthAmerica);
	Mexico.addAdjacentCountry(&Canada);
	Mexico.addAdjacentCountry(&USA);
	Greenland.setCountryName("Greenland");
	Greenland.setContinent(&Europe);
	Greenland.addAdjacentCountry(&Canada);

	worldMap.addCountry("Canada", &Canada);
	worldMap.addCountry("USA", &USA);
	worldMap.addCountry("Mexico", &Mexico);
	worldMap.addCountry("Greenland", &Mexico);

	cout << Canada.getCountryName() << " in "<< Canada.getContinent()->getContinentName() << " belongs to " << Canada.getOwner()->getPlayerName() <<
		" and has an army of " << Canada.getArmyNumber() << endl;

	cout << "Canada's adjacent countries are: ";
	Canada.printAdjacentCountry();

	cout << "Greenland's adjacent countries are: ";
	Greenland.printAdjacentCountry();

	cout << "Is the graph connected: " << worldMap.ifConnectedGraph(&Canada) << endl;
	cout << "Is North America connected: " << worldMap.ifConnectedContinent(&Canada, &NorthAmerica) << endl;

	// including new country that will not be connected to any other country
	Country China;
	worldMap.addCountry("China", &China);
	// LET'S SAY CHINA IS IN NORTH AMERICA
	China.setContinent(&NorthAmerica);

	cout << "Is the graph connected with China: " << worldMap.ifConnectedGraph(&Canada) << endl;
	cout << "Is North America connected with China: " << worldMap.ifConnectedContinent(&Canada, &NorthAmerica) << endl;
	system("pause");
	return 0;
}