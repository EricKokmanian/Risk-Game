#pragma once
#include <string>
using namespace std;
#ifndef CARD_H
#define CARD_H

class Card
{
public:
	Card();
	~Card();
	string getType();

private:
	string type;
};
#endif

