#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player {

	private:
		string name;

	public:	
		Player();
		Player(string name);
		string getPlayerName();
		void setPlayerName(string name);
};