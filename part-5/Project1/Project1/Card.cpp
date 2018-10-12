#include "Card.h"
#include <cstdlib>



Card::Card() {

}

Card::Card(int number) {
	string CardType[] = { "Infantry", "Artillery", "Cavalry" };
	type = CardType[number % 3];
}

Card::~Card()
{
}

string Card::getType()
{
	return type;
}
