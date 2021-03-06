#include <iostream>
#include "startupPhase.h"

#include <algorithm>

using namespace std;

//default constructor
startupPhase::startupPhase() {
}

//constructor that takes a vector of size between 2 and 6
startupPhase::startupPhase(vector <Player*> order) {
	if ((int)order.size() < 2 || (int)order.size() > 6) {
		cout << "Error! the number of players entered is incorrect" << endl;
		system("pause");
		exit(1);
	}

	this->order = order;

}

//a method to rnadomize the order of play for the players
vector<Player*> startupPhase::orderOfPlay(vector <Player*> players) {

	std::random_shuffle(players.begin(), players.end());
	cout << "the order of players is: " << endl;
	for (int i = 0; i < (int)players.size(); i++)
	{
		cout << i + 1 << " : " << players.at(i)->getPlayerName() << endl;
	}
	return players;

}

//a method to assign countries randomly to players
void startupPhase::assignCountries(vector <Country*> co, vector <Player*> x) {
	try {
		std::random_shuffle(countries.begin(), countries.end());
		for (int j = 0; j < (int)co.size(); j++)
		{
			for (int i = 0; i < (int)x.size(); i++)
			{
				x.at(i)->addCountry(co.at(j));
				co.at(j)->setOwner(x.at(i));
				cout << " The owner of: " << co.at(j)->getCountryName() << " is: " << x.at(i)->getPlayerName() << endl;
				//	co.pop_back();
				j++;

			}
		}
	}
	catch (std::exception e) { printf("EROR: %s", e.what()); }
}

//a method that gives each player an army based on how many players there are
void startupPhase::provideArmy(vector<Player*> players) {

	if ((int)players.size() == 2) {
		for (Player* i : players)
		{
			i->setNumberOfArmy(40);
		}
	}
	else if ((int)players.size() == 3) {
		for (Player* i : players)
		{
			i->setNumberOfArmy(35);
		}
	}
	else if ((int)players.size() == 4) {
		for (Player* i : players)
		{
			i->setNumberOfArmy(30);
		}
	}
	else if ((int)players.size() == 5) {
		for (Player* i : players)
		{
			i->setNumberOfArmy(25);
		}
	}
	else if ((int)players.size() == 6) {
		for (Player* i : players)
		{
			i->setNumberOfArmy(20);
		}
	}
}

// void startupPhase::placeArmy(int n, vector<Player*> players) {

//	for(int)
//	}

//a method that will let players place the army given one by one on their countries
void startupPhase::placeArmy(int n, vector<Player*> players, vector<Country*> countries) {
	while (checkVisited(countries) == false) {
		for (auto it = players.begin(); it != players.end(); ++it) {

			vector<Country*> countriesLeft;
			cout << (*it)->getPlayerName() << ", you have " << (*it)->getNumberOfArmy() << " left to place." << endl;
			cout << "Please enter the number of which country you want to add armies to" << endl;
			int counter = 1;

			vector<Country*>::size_type size = (*it)->getCountries().size();
			for (vector<Country*>::size_type i = 0; i < size; ++i) {
				if ((*it)->getCountries()[i]->getVisited() == false) {
					cout << counter << ". " << (*it)->getCountries()[i]->getCountryName() << endl;
					countriesLeft.push_back((*it)->getCountries()[i]);
					counter++;
				}
			}

			int playerChoice = 0;
			cin >> playerChoice;
			Country* chosenCountry = countriesLeft[playerChoice - 1];
			cout << "You chose to add armies to " << chosenCountry->getCountryName() << endl;
			cout << "How many armies do you want to add?" << " You have " << (*it)->getNumberOfArmy() << " left." << endl;
			while (true) {
				cin >> playerChoice;
				if ((*it)->getNumberOfArmy() < playerChoice) {
					cout << "You cannot exceed your army size limit" << endl;
				}
				else {
					break;
				}
			}
			chosenCountry->setArmyNumber(playerChoice);
			(*it)->setNumberOfArmy((*it)->getNumberOfArmy() - playerChoice);
			chosenCountry->setVisited(true);
			cout << chosenCountry->getCountryName() << " now has an army of " << chosenCountry->getArmyNumber() << endl;
			cout << (*it)->getNumberOfArmy() << " remains to be placed" << endl;

		}
	}
}

bool startupPhase::checkVisited(vector<Country*> countries) {
	for (auto it = countries.begin(); it != countries.end(); ++it) {
		if ((*it)->getVisited() != true) {
			return false;
		}
	}
	return true;
}

//
//for (int i = 0; i < (int)players.size(); i++)
//{
//	int x = players.at(i)->getNumberOfArmy() / players.at(i)->getCountries().size();
//	int left = players.at(i)->getNumberOfArmy() % players.at(i)->getCountries().size();
//	if (left == 0)
//	{
//		for (int i = 0; i < (int)players.at(i)->getCountries().size(); i++)
//		{
//			players.at(i)->getCountries().at(i)->setArmyNumber(x);
//			players.at(i)->setNumberOfArmy(players.at(i)->getNumberOfArmy() - x);
//		}
//	}
//
//
//}