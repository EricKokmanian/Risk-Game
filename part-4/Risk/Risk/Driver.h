#include "Country.h"
#include"Player.h"
#include"Continent.h"


using namespace std;
class Driver
{
private:
	vector<Player> players;
public:
	Driver();
	~Driver();
	void start();
	void reinforce(Player* p, int* multiplier);
	void attack(Player* p);
	void fortify(Player* p);
};

