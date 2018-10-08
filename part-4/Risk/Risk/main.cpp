#include <iostream>
#include <string>

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
	Country Spain("Spain");
	Country Portugal("Portugal");
	Country UK("UK");
	Country Italy("Italy");
	Country Germany("Germany");
	Canada.setOwner(&David);
	USA.setOwner(&David);
	Portugal.setOwner(&David);
	Italy.setOwner(&David);
	Germany.setOwner(&David);

	UK.setOwner(&John);
	Mexico.setOwner(&John);
	France.setOwner(&John);
	Spain.setOwner(&John);

	David.addCountry({ &Canada, &USA, &Portugal, &Italy, &Germany });
	John.addCountry({ &UK, &Mexico, &France, &Spain });

	Card newcard1;
	Card newcard2;
	David.addToHand(&newcard1);
	David.addToHand(&newcard2);

	Dice diceObj;
	David.addDice(&diceObj);

	cout << "List of owners of Canada: " << Canada.getOwnerName() << endl;
	cout << "Type of cards that David has : " << newcard1.getType() << "and" << newcard2.getType() << endl;

	system("pause");
}
