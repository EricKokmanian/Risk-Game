#include "Hand.h"

Hand::Hand()
{
}


Hand::~Hand()
{
}

void Hand::addCard(Card *)
{
}

void Hand::removeCard()
{
	hand.pop_back();
}

void Hand::draw()
{
	
}

void Hand::draw(Card * card)
{
	hand.push_back(card);
}
