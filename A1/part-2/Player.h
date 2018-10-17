#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player {
	
	public :
		Player();
		Player(string ownerName);
		string getPlayer();
		void setPlayer(string ownerName);
		
	private :
		string name;
};