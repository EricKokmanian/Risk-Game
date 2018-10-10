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
	cards.push_back((new Card));
}
