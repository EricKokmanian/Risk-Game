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

	Player David("David");
	Player John("John");
	Country Canada("Canada");
	Country USA("USA");
	Country Mexico("Mexico");
	Country France("France");
	Canada.setOwner(David);
	USA.setOwner(David);

	Mexico.setOwner(John);
	France.setOwner(John);

	Hand h1;
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	David.setHand(&h1);

	Dice diceObj;
	David.addDice(&diceObj);
	vector<int> v = David.getDice()->roll(2);

	stringstream ss;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (i != 0)
			ss << ",";
		ss << v[i];
	}
	string s = ss.str();


	cout << "Owner of Canada: " << Canada.getOwnerName() << endl;
	cout << "Owner of Mexico: " << Mexico.getOwnerName() << endl;
	cout << "David's cards: " << David.getHand() << endl;
	cout << "David rolls 2 dice and gets: " << s << endl;


	system("pause");
}
