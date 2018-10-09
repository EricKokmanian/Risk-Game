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
	
	cout << c.getCountryName() << " belongs to " << c.getOwner -> getPlayer() << endl;
	
	c.setOwner(&p2);
	
	cout << c.getCountryName() << " belongs to " << c.getOwner -> getPlayer() << endl;

}