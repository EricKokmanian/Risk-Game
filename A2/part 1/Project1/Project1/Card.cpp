#include "Card.h"
#include <cstdlib>


string CardType[] = { "Infantry", "Artillery", "Cavalry" };

Card::Card()
{
	int value = rand() % (3);
	type = CardType[value];

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
