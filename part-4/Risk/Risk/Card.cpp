#include "Card.h"
#include <cstdlib>


string CardType[] = { "Infantry", "Artillery", "Cavalry" };

Card::Card()
{
	int value = rand() % (3);
	type = CardType[value];

}

Card::~Card()
{
}

string Card::getType()
{
	return type;
}
