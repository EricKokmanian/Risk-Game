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
	void addCard(Card*);
	void removeCard(Card*);

private:
	vector<Card*> hand;
};
#endif
