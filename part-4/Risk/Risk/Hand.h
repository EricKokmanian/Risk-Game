#pragma once
#ifndef HAND_H
#define HAND_H
#include <vector>
#include "Card.h"
using namespace std;

class Hand
{
public:
	Hand();
	~Hand();
	void addCard(Card* card);
	void removeCard();
	void draw();
	void draw(Card* card);
	vector<Card*> getCards() { return hand; }


public:
	vector<Card*> hand;
};
#endif
