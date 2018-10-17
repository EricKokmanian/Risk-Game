#pragma once
#include <string>
using namespace std;


class Card
{
	public:
		Card();
		Card(int);
		~Card();
		string getType();

	private:
		string type;
};