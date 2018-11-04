#pragma once
#include <vector>
#include <string>
#include "Map.h"

using namespace std;

class MapManager {
private :

public :
	const vector<string> split(const string &s, const char &c);
	Map* verifyMap(string);

};
