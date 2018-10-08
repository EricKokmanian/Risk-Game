#include "Driver.h"



Driver::Driver()
{
}


Driver::~Driver()
{
}

void Driver::start()
{
}

void Driver::reinforce(Player* p, int* multiplier)
{
	int nb = (p->getCountries().size())/3;
	if (nb < 3)
		nb = 3;

	for (auto &c : p->getContinents) {
		if (c.getContinentName() == "North America") {
			nb += 5;
		}
		if (c.getContinentName() == "Asia") {
			nb += 7;
		}
		if (c.getContinentName() == "Europe") {
			nb += 5;
		}
		if (c.getContinentName() == "South America") {
			nb += 2;
		}
		if (c.getContinentName() == "Africa") {
			nb += 3;
		}
		if (c.getContinentName() == "Australia") {
			nb += 2;
		}
	}
	if (p->getHand().size() >= 3) {
		nb += ((*multiplier)*5);
		++ (*multiplier);
		p->hand->removeCard();
		p->hand->removeCard();
		p->hand->removeCard();
	}

	p->setNumberOfArmy(nb);
}

void Driver::attack(Player* p)
{
}

void Driver::fortify(Player* p)
{
}
