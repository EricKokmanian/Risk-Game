#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

#include "MapManager.h"
#include "Country.h"
#include "Player.h"
#include "Continent.h"
#include "Map.h"

// Explode class that will split the strings with commas into string tokens 
const vector<string> MapManager::split(const string &s, const char &c)
{
	string str{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c)
			str += n;
		else
			if (n == c && str != "") {
				v.push_back(str);
				str = "";
			}
	}
	if (str != "")
		v.push_back(str);

	return v;
}

Map* MapManager::verifyMap(string mapName) {

	Map* worldMap = new Map(); // Instantiation the Map object -- SHOULD BE A POINTER
	bool isValid = false; // Flag checking whether continents are connected
	bool isValid2 = false; // Flag checking whether countries are connected
	bool once = false;
	bool twice = false;
	bool mapInfo = false; // Flag checking wether file has map info
	bool continentInfo = false; // Flag checking wether file has continent info
	bool countryInfo = false; // Flag checking wether file has territory info

	Continent* northAmerica = NULL;
	Continent* southAmerica = NULL;
	Continent* africa = NULL;
	Continent* europe = NULL;
	Continent* asia = NULL;
	Continent* australia = NULL;
	Continent* contPtr = NULL;

	ifstream ifs; // File input stream
	ifstream ifs2;
	string firstLine;
	string firstLine2;
	string contName;
	string continent;
	string contBonus;
	int bonus = 0;
	int contNbr = 0;
	string terrName;
	Country* count = NULL;
	Country* count2 = NULL;

	vector<string> vect;

	// Opening map file specified by user
	ifs.open("C:\\Users\\erick_000\\Documents\\GitHub\\Risk-Game\\A4\\part 2\\Project1\\Project1\\Map files\\" + mapName);

	if (ifs.is_open()) {

		// Map info
		while (!ifs.eof() && firstLine != "[Continents]") {
			firstLine.clear();
			getline(ifs, firstLine, '\n');
			cout << firstLine << endl;
			mapInfo = true;

			if (ifs.eof())
				continentInfo = false;
		}

		// Instantiate Continents
		while (!ifs.eof() && contName != "[Territories]") {
			contName.clear();
			getline(ifs, contName, '\n');
			cout << contName << endl;

			if (contName != "" && contName != "\n" && contName.size() > 2) {
				++contNbr;
				continent = contName.substr(0, contName.size() - 2); // Select Continent Name

				if (continent == "North America")
					northAmerica = new Continent(continent);
				else if (continent == "Europe")
					europe = new Continent(continent);
				else if (continent == "South America")
					southAmerica = new Continent(continent);
				else if (continent == "Africa")
					africa = new Continent(continent);
				else if (continent == "Asia")
					asia = new Continent(continent);
				else if (continent == "Australia")
					australia = new Continent(continent);
				else
					contPtr = new Continent(continent);
			}

			if (continent != contBonus || contName.size() > 2)
				continentInfo = true;
		}


		// Instantiate Countries
		while (!ifs.eof() && mapInfo && continentInfo) {
			countryInfo = true;
			terrName.clear();
			getline(ifs, terrName, '\n'); // Add line to a created string 'terrName'

			if (terrName != " " && terrName != "") { // Check that line is not empty
				vector<string> vect1{ split(terrName,',') };

				Continent* contPtr = NULL;
				if (vect1.at(3) == "North America")
					contPtr = northAmerica;
				else if (vect1.at(3) == "South America")
					contPtr = southAmerica;
				else if (vect1.at(3) == "Europe")
					contPtr = europe;
				else if (vect1.at(3) == "Asia")
					contPtr = asia;
				else if (vect1.at(3) == "Africa")
					contPtr = africa;
				else if (vect1.at(3) == "Australia")
					contPtr = australia;

				Country* c1 = new Country(vect1.at(0), NULL, 0, contPtr); // Instantiate Country object using constructor
				cout << c1->getCountryName() << " is now a country in " << c1->getContinent()->getContinentName() << "." << endl;

				// Adding newest country to Map
				worldMap->addCountry(c1->getCountryName(), c1);
				//cout << "Map has a size of : " << worldMap->getSize() << endl; // WHY IS IT ALWAYS ONE??

				if (once == false) {
					count = new Country(vect1.at(0), NULL, 0, contPtr);
					cout << "Count: " << count->getCountryName() << endl;
					once = true;
				}

				//if (mapInfo == true && continentInfo == true && countryInfo == true) {
					// Checks whether continents are connected
				if (ifs.eof()) {

					try {
						ifs2.open("C:\\Users\\erick_000\\Documents\\GitHub\\Risk-Game\\A2\\part 1\\Project1\\Project1\\Map files\\" + mapName);

						if (ifs2.is_open()) {

							// Skipping irrelevant info
							while (!ifs2.eof() && firstLine2 != "[Territories]") {
								firstLine2.clear();
								getline(ifs2, firstLine2, '\n');
							}

							// Teritories info
							while (!ifs2.eof()) {
								terrName.clear();
								getline(ifs2, terrName, '\n');

								if (terrName != " " && terrName != "") { // Check that line is not empty
									vector<string> vect1{ split(terrName,',') };

									Country* country = worldMap->getCountry(vect1.at(0)); //CRASHES! CUS ONLY ONE (LAST) COUNTRY IN MAP

									// Adding adjacent countries...
									for (int z = 4; z < vect1.size(); z++) {
										Country* neighbor = NULL;
										neighbor = worldMap->getCountry(vect1.at(z));
										country->addAdjacentCountry(neighbor);

									}

									cout << country->getCountryName() << " is now a neighbor of : " << endl;
									country->printAdjacentCountry();
									cout << "\n" << endl;
								}
							}

						}

						cout << "Neighbors of Alaska in " << worldMap->getCountry("Alaska")->getContinent()->getContinentName() << " are : " << endl;
						worldMap->getCountry("Alaska")->printAdjacentCountry();

						/*cout << "\nThis map has initialized a total of " << worldMap->getSize() << " countries..." << endl;*/

						cout << "Spread out on " << (contNbr - 1) << " different continents." << endl;
						cout << "-------------------------------------------------------------\n" << endl;

						/*cout << "1) Checking if continents are connected : ..." << endl;
						isValid = worldMap->ifConnectedContinent(worldMap->getCountry("Alaska"), worldMap->getCountry("Alaska")->getContinent());
						cout << (isValid ? "---> TRUE\n" : "---> FALSE\n") << endl;
						twice = true;*/
					}
					catch (...) {
						isValid = false;
						cout << isValid << endl;
					}

				}

				// Checking whether countries are connected
				/*if (twice == true) {
					count2 = new Country(*c1);
					count2->printAdjacentCountry();
					twice = false;
				}*/

				/*if (ifs.eof()) {
					cout << "2) Checking if countries are connected : ..." << endl;
					isValid2 = worldMap->ifConnectedGraph(count2);
					cout << (isValid2 ? "---> TRUE\n" : "---> TRUE\n") << endl;
				}*/
				/*}
				else {
					cout << "Something went wrong when trying to read map file..." << endl;
					cout << "Map info : " << mapInfo << endl;
					cout << "Continents info : " << continentInfo << endl;
					cout << "Territories info : " << countryInfo << endl;
				}*/


			}
			else
				continue;
		}

		if (ifs.eof()) {
			if (countryInfo == true) {}
			else
				countryInfo = false;
		}


		if (mapInfo == false || continentInfo == false || countryInfo == false) {
			cout << "Something went wrong when trying to read map file..." << endl;
			cout << "Map info : " << mapInfo << endl;
			cout << "Continents info : " << continentInfo << endl;
			cout << "Territories info : " << countryInfo << endl;
		}
	}
	else
		cout << "File is not open.";

	ifs.close();
	system("pause");

	return worldMap;
	//delete worldMap;

}