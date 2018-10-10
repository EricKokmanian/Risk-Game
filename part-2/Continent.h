#pragma once
#include <iostream>
#include <string>

using namespace std;

class Continent {
	
	public :
		Continent();
		Continent(string contName);
		string getContName();
		void setContName(string contName);
		
	private :
		string name;
};	