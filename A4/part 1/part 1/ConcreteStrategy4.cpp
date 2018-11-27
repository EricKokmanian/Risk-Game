#include "ConcreteStrategy4.h"
#include "FortificationPhase.h"
#include "AttackPhase.h"
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



ConcreteStrategy4::ConcreteStrategy4()
{
}


ConcreteStrategy4::~ConcreteStrategy4()
{
}

void ConcreteStrategy4::reinforce(Map worldmap, Player *player)
{
	int x = worldmap.getNumberOfCountries(*player);
	if (x < 3) {
		x = 3;
	}

	string name;
	cout << "Here are the countries owned by " << player->getName() << " : " << player->getCountries(1) << endl << "We will double all the armies of these countries " << endl;
	for (int a = 0;a < player->getCountries().size(); a++) {
		cout << player->getCountries()[a]->getCountryName() << " had " << player->getCountries()[a]->getArmyNumber() << " armies. ";
		player->getCountries()[a]->setArmyNumber(player->getCountries()[a]->getArmyNumber() * 2);
		cout << "Now it has: " << player->getCountries()[a]->getArmyNumber() << " armies." << endl;
	}

	cout << "-------- END OF REINFORCEMENT PHASE ---------" << endl;
}

void ConcreteStrategy4::attack(Player *player)
{
	cout << "Conquering all neighboring countries of " << player->getName() << endl << endl;

	for (int i = 0;i < player->getCountries().size(); i++) {
		cout << player->getCountries()[i]->getCountryName() << " has the following neighboring countries : " << endl;
		for (int x = 0;x < player->getCountries()[i]->getAdjacentCountries().size();x++) {
			cout << player->getCountries()[i]->getAdjacentCountries()[x]->getCountryName() << endl;
			player->getCountries()[i]->getAdjacentCountries()[x]->setOwner(player);

			//adding the country into player's countries vector
			if (find(player->getCountries().begin(), player->getCountries().end(), player->getCountries()[i]->getAdjacentCountries()[x]) != player->getCountries().end()) {
				/* player contains the country */
			}
			else {
				player->addCountry(player->getCountries()[i]->getAdjacentCountries()[x]);
			}
		}
	}
	cout << "These countries are now all owned by " << player->getName() << endl << endl;

	cout << "Here are all the countries owned by " << player->getName() << " :" << player->getCountries(1)<<endl;

	cout << "-------- END OF ATTACK PHASE ---------" << endl;
}

void ConcreteStrategy4::fortify(Map worldMap,Player *player)
{
	for (auto const &ent1 : worldMap.getMap()) {
		if (ent1.second->getOwner() != player) {
			cout << "The neighboring country "<< ent1.second->getCountryName() << " is owned by " << ent1.second->getOwnerName() << endl;
			cout << ent1.second->getCountryName() << " has " << ent1.second->getArmyNumber() << " armies. " << endl;
			ent1.second->setArmyNumber(ent1.second->getArmyNumber() * 2);
			cout << "It now has " << ent1.second->getArmyNumber() << " armies!" << endl;
		}
	}



	cout << "-------- END OF FORTIFY PHASE ---------" << endl;
}
