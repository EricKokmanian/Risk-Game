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
	//add new cards into that vector of cards
	void draw();


public:
	vector<Card*> cards;
};
#endif
