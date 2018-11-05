#include <iostream>
#include "startupPhase.h"
//#include <time.h>
//#include <stdlib.h>

using namespace std;

int main() {

	//creating a startupPhase object
	startupPhase start;

	//creating players objects
	Player David("David");
	Player John("John");
	Player Eric("Eric");

	//creating country objects
	Country Canada("Canada");
	Country USA("USA");
	Country Mexico("Mexico");
	Country Italy("Italy");
	Country Spain("Spain");
	Country UK("UK");
	Country Turkey("Turkey");


	//creating a vector to hold all the countries
	vector <Country*> countries;
	countries.push_back(&Canada);
	countries.push_back(&USA);
	countries.push_back(&Mexico);
	countries.push_back(&Italy);
	countries.push_back(&Spain);
	countries.push_back(&UK);
	countries.push_back(&Turkey);


	//creating a vector to hold all the players
	vector <Player*> players;
	players.push_back(&David);
	players.push_back(&John);
	players.push_back(&Eric);

	vector <Player*> players2;

	//printing out the countries in the vector
	for (int i = 0; i < (int)countries.size(); i++)
		std::cout << countries.at(i)->getCountryName() << " ";
	cout << endl;

	//printing out the players in the vector
	for (int i = 0; i < (int)players.size(); i++)
		std::cout << players.at(i)->getPlayerName() << " ";
	cout << endl;

	system("pause");

	//randomizing the order of play
	players2 = start.orderOfPlay(players);

	//giving each player in the array a number of armies corresponding to how many players there are
	start.provideArmy(players2);

	//printing out the player name in the array followed by the army number each player has
	for (int i = 0; i < (int)players2.size(); i++)
		std::cout << players2.at(i)->getPlayerName() << " ";
	cout << endl;
	system("pause");
	for (int i = 0; i < (int)players2.size(); i++)
		std::cout << players2.at(i)->getNumberOfArmy() << " ";
	cout << endl;
	system("pause");
	/*
		Canada.setOwner(&David);
		USA.setOwner(&John);
		Mexico.setOwner(&Eric);
		Germany.setOwner(&David);
		Italy.setOwner(&John);
		Spain.setOwner(&Eric);
		UK.setOwner(&David);
		Turkey.setOwner(&John);

		David.addCountry(&Canada);
		John.addCountry(&USA);
		Eric.addCountry(&Mexico);
		David.addCountry(&Germany);
		John.addCountry(&Italy);
		Eric.addCountry(&Spain);
		David.addCountry(&UK);
		John.addCountry(&Turkey);

		*/

		//assigning countries randomly to each player
	start.assignCountries(countries, players2);
	system("pause");

	//Here is my problem! placing the army for each of the players
	start.placeArmy(35, players2, countries);

	//printing out to see what happend
	//for (int i = 0; i<(int)players2.size(); i++)
	//	std::cout << players2.at(i)->getPlayerName() << " ";
	//cout << endl;

	//system("pause");
	//for (int i = 0; i<(int)players2.size(); i++)
	//	std::cout << players2.at(i)->getNumberOfArmy() << " ";
	//cout << endl;
	//system("pause");

	system("pause");


	return 0;
}