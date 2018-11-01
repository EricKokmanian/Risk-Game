#include "Country.h"
#include"Player.h"
#include"Continent.h"
#include "Map.h"

using namespace std;
class Driver
{
private:
	vector<Player> players;
public:
	Driver();
	~Driver();
	void start();
	void reinforce(Map worldmap, Player player);
	void reinforce2(Map worldmap, Player player);
	void reinforce3(Map worldmap, Player player);
	void attack(Player* p);
	void fortify(Player* p);
};

