#include "Country.h"
#include"Player.h"
#include"Continent.h"

#ifndef DRIVER_H
#define DRIVER_H
using namespace std;
class Driver
{
private:
	vector<Player> players;
public:
	Driver();
	~Driver();
	void start();
	void reinforce(Player& p);
	void attack(Player& p);
	void fortify(Player& p);
};
#endif

