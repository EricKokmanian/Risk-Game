#include "Hand.h"
#include "Card.h"
#include <string>
#include <sstream>
#include <iostream>

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


