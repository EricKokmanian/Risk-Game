#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

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

int MapManager::function1() {

	Map worldMap; // Instantiation the Map object
	bool isValid = false; // Flag checking whether continents are connected
	bool isValid2 = false; // Flag checking whether countries are connected
	bool once = false;
	bool twice = false;
	bool mapInfo = false; // Flag checking wether file has map info
	bool continentInfo = false; // Flag checking wether file has continent info
	bool countryInfo = false; // Flag checking wether file has territory info

	ifstream ifs; // File input stream
	string firstLine;
	string contName;
	string continent;
	string contBonus;
	int bonus = 0;
	int contNbr = 0;
	string terrName;
	Country* count = NULL;
	Country* count2 = NULL;
	Country* neighbor = NULL;

	vector<string> vect;

	// Opening map file
	ifs.open("map.txt");

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
				//contBonus =  contName.substr(contName.size() - 1, contName.size()); // Select Continent Bonus Pts
				//bonus = stoi(contBonus);
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

				//for (int i = 0; i < vect1.size(); i++) {
				//	cout << vect1.at(i) << endl;
				//}

				Continent *contPtr = new Continent(vect1.at(3)); // Instantiate continent

				Country c1(vect1.at(0), contPtr); // Instantiate Country object using constructor
				//cout << c1.getContinent()->getContName() << endl;

				// Adding adjacent countries...
				for (int z = 4; z < vect1.size(); z++) {
					neighbor = new Country(vect1.at(z));
					c1.addAdjacentCountry(neighbor);

				}

				if (once == false) {
					count = new Country(vect1.at(0), contPtr);
					cout << "Count: " << count->getCountryName() << endl;
					once = true;
				}

				// Add countries to map obj
				worldMap.addCountry(c1.getCountryName(), &c1);

				cout << c1.getCountryName() << " is a country in " << c1.getContinent()->getContName() << " its neighbors are : " << endl;
				c1.printAdjacentCountry();
				cout << "" << endl;

				if (mapInfo == true && continentInfo == true && countryInfo == true) {
					// Checks whether continents are connected
					if (ifs.eof()) {
						try {
							//cout << "This map has initialized a total of " << worldMap.getSize() << " countries..." << endl;
							cout << "Spread out on " << (contNbr - 2) << " different continents." << endl;
							cout << "-------------------------------------------------------------\n" << endl;

							cout << "1) Checking if continents are connected : ..." << endl;
							isValid = worldMap.ifConnectedContinent(count, count->getContinent());
							cout << (isValid ? "---> TRUE\n" : "---> FALSE\n") << endl;
							twice = true;
						}
						catch (...) {
							isValid = false;
							cout << isValid << endl;
						}

					}

					// Checking whether countries are connected
					if (twice == true) {
						count2 = new Country(c1);
						count2->printAdjacentCountry();
						twice = false;
					}

					if (ifs.eof()) {
						cout << "2) Checking if countries are connected : ..." << endl;
						isValid2 = worldMap.ifConnectedGraph(count2);
						cout << (isValid2 ? "---> TRUE\n" : "---> TRUE\n") << endl;
					}
				}
				else {
					cout << "Something went wrong when trying to read map file..." << endl;
					cout << "Map info : " << mapInfo << endl;
					cout << "Continents info : " << continentInfo << endl;
					cout << "Territories info : " << countryInfo << endl;
				}
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

}