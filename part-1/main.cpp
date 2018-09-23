#include <iostream>
#include <string>

using namespace std;
#include "Country.h"
#include "Player.h"

int main() {

	Player John("John");
	Player Tony("Tony");

	Country Canada;

	Canada.setCountryName("Canada");
	Canada.setOwner(&John);
	Canada.setArmyNumber(5);


	cout << Canada.getCountryName() << " belongs to " << Canada.getOwner()->getPlayerName() <<
		" and has an army of " << Canada.getArmyNumber() << endl;

	system("pause");
}