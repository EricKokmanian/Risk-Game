#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#include "Country.h"
#include "Player.h"
#include "Card.h"
#include "Hand.h"


int main() {

	// I create the player objects
	Player David("David");
	Player John("John");

	//I create country objects
	Country Canada("Canada");
	Country USA("USA");
	Country Mexico("Mexico");
	Country France("France");

	//I assign countries to the Player objects
	David.addCountry(&Canada);
	David.addCountry(&USA);
	John.addCountry(&Mexico);
	John.addCountry(&France);

	//I create a hand
	Hand h1;

	//I draw random cards in that hand
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();

	//I assign that hand to David
	David.setHand(&h1);

	//I create a dice
	Dice diceObj;

	//I assign it to David
	David.addDice(&diceObj);

	//I roll the dice twice and put the results in a vector
	vector<int> v = David.getDice()->roll(2);

	//I convert that vector to a list of strings
	stringstream ss;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (i != 0)
			ss << ",";
		ss << v[i];
	}
	string s = ss.str();

	//Empty methods
	David.reinforce();
	David.attack();
	David.fortify();

	cout << "Countries of David: " << David.getCountries() << endl;
	cout << "David's cards: " << David.getHand() << endl;
	cout << "David rolls 2 dice and gets: " << s << endl;


	system("pause");
}
