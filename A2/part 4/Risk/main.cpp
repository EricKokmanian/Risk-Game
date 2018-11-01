#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#include "Country.h"
#include "Player.h"
#include "Card.h"
#include "Hand.h"
#include "Map.h"
#include "Driver.h"

int main() {

	//create players
	Player David("David");
	Player John("John");

	//create countries
	Country Canada("Canada");
	Country USA("USA");
	Country Mexico("Mexico");
	Country France("France");
	Country Indonesia("Indonesia");
	Country NewGuinea("New Guinea");
	Country WesternAustralia("Western Australia");
	Country EasternAustralia("Eastern Australia");
	
	//create maps and assign countries to map
	Map worldMap;
	Map worldMap2;
	worldMap.addCountry("Canada", &Canada);
	worldMap.addCountry("USA", &USA);
	worldMap.addCountry("Mexico", &Mexico);
	worldMap2.addCountry("Indonesia", &Indonesia);
	worldMap2.addCountry("New Guinea", &NewGuinea);
	worldMap2.addCountry("Western Australia", &WesternAustralia);
	worldMap2.addCountry("Eastern Australia", &WesternAustralia);

	//add countries to david
	David.addCountry(&Canada);
	David.addCountry(&USA);
	David.addCountry(&Mexico);
	Canada.setOwner(&David);
	USA.setOwner(&David);
	Mexico.setOwner(&David);

	//add countries to John
	Indonesia.setOwner(&John);
	WesternAustralia.setOwner(&John);
	EasternAustralia.setOwner(&John);
	NewGuinea.setOwner(&John);
	John.addCountry(&Indonesia);
	John.addCountry(&WesternAustralia);
	John.addCountry(&EasternAustralia);
	John.addCountry(&NewGuinea);

	Driver d;

	//reinforce method for player David while having a few countries in possession
	//d.reinforce(worldMap, David);

	//reinforce method for player John while having Australia as a continent value
	//d.reinforce2(worldMap2, John);

	Hand h1;
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	h1.draw();
	David.setHand(&h1);

	d.reinforce3(worldMap, David);

	system("pause");
}
