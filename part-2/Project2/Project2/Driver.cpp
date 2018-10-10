#include <iostream>
#include <string>

using namespace std;

#include "Country.h"
#include "Player.h"
#include "Continent.h"
#include "Map.h"

int main() {

	Map worldMap;

	Player p1("Tom");
	Player p2("Jerry");

	Country c;
	Country c2;
	Country c3;

	Continent cont;
	cont.setContName("North America");

	c.setCountryName("Canada");
	c.setOwner(&p1);
	c.setArmyNumber(3);
	c.setContinent(&cont);

	c2.setCountryName("USA");
	c2.setOwner(&p2);
	c2.setArmyNumber(4);
	c2.setContinent(&cont);

	cout << c.getCountryName() << " belongs to " << c.getOwner()->getPlayer() << " and has an army of " << c.getArmyNumber() << endl;

	c.setOwner(&p2);

	cout << c.getCountryName() << " belongs to " << c.getOwner()->getPlayer() << " and has an army of " << c.getArmyNumber() << endl;

}