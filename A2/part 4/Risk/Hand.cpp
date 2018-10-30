#include "Hand.h"
#include "Card.h"
#include <string>
#include <sstream>

using namespace std;

Hand::Hand()
{
}


Hand::~Hand()
{
}

void Hand::draw()
{
	Card c;
	cards.push_back(c);
}
