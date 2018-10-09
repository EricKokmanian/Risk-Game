#include <iostream>
#include <string>

using namespace std;

#include "Country.h"
#include "Player.h"

int main() {
	Player p1 ("Tom");
	Player p2 ("Jerry");
	
	Country c;
	
	c.setCountryName("Canada");
	c.setOwner(&p1);
	c.setArmyNumber(3);
	
	cout << c.getCountryName() << " belongs to " << c.getOwner -> getPlayer() << " and has an army of " << c.getArmyNumber() << endl;
	
	c.setOwner(&p2);
	
	cout << c.getCountryName() << " belongs to " << c.getOwner -> getPlayer() << " and has an army of " << c.getArmyNumber() << endl;

}