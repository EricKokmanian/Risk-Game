#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Country.h"
#include "Player.h"
#include "Continent.h"
#include "Map.h"

// Explode class that will split the strings with commas into string tokens 
const vector<string> split(const string &s, const char &c)
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

int main() {

	Map worldMap; // Instantiation the Map object
	bool isValid = false; // Flag
	bool once = false;

	ifstream ifs;
	string firstLine;
	string contName;
	string continent;
	int contNbr = 0;
	string terrName;
	Country* count = NULL;

	vector<string> vect;

	// Opening map file
	ifs.open("map.txt");

	if (ifs.is_open()) {

		// Map info
		while (! ifs.eof() && firstLine != "[Continents]") {
			firstLine.clear();
			getline(ifs, firstLine, '\n');
			cout << firstLine << endl;

		}

		// Instantiate Continents
		while (! ifs.eof() && contName != "[Territories]") {
			contName.clear();
			getline(ifs, contName, '\n');
			cout << contName << endl;
			continent = contName.substr(0, contName.size() - 2); // Select Continent Name
			
			if(contName != "" || contName != "\n")
				++contNbr;
			//Continent conti(continent);
			//newContinent.setContName(continent); // Instantiate new continents
			//cout << continent << endl;
			//cout << contName.substr(contName.size() - 1, contName.size()) << endl; // Select Continent Bonus Pts
		}


		// Instantiate Countries
		while (!ifs.eof()) {
			terrName.clear();
			getline(ifs, terrName, '\n'); // Add line to a created string 'terrName'
			//cout << terrName << endl;

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
					Country* neighbor = new Country(vect1.at(z));
					c1.addAdjacentCountry(neighbor);

				}

				if (once == false) {
					count = new Country(vect1.at(0), contPtr);
					cout << "Count: " << count->getCountryName() << endl;
					once = true;
				}

				// Add countries to map obj
				worldMap.addCountry(c1.getCountryName(), &c1);

				cout << c1.getCountryName() << " is a country in " << c1.getContinent()-> getContName() << " its neighbors are : " << endl;
				c1.printAdjacentCountry();
				cout << "" << endl;
				
				if (ifs.eof()) {
					try {
						cout << "This map has initialized a total of " << worldMap.getSize() << " countries..." << endl;
						cout << "Spread out on " << (contNbr - 2) << " different continents." << endl;
						cout << "-------------------------------------------------------------\n" << endl;

						cout << "1) Checking if continents are connected : ..." << endl;
						isValid = worldMap.ifConnectedContinent(count, count->getContinent());
						cout << (isValid ? "---> TRUE\n" : "---> FALSE\n") << endl;

						cout << "2) Checking if countries are connected : ..." << endl;
						cout << count->getCountryName() << endl;
						count->printAdjacentCountry(); //not printing!
						isValid = worldMap.ifConnectedGraph(count);
						cout << (isValid ? "---> TRUE\n" : "---> FALSE\n") << endl;
						
					}
					catch (...) {
						isValid = false;
						cout << isValid << endl;
					}

				}
			}
			else
				continue;

			//if (ifs.eof()) {
			//	try {
			//	cout << count.getCountryName() << endl;
			//	unordered_map<string, Country*> temp = worldMap.getWorldMap();
			//	cout << temp[count.getCountryName()] << endl;
			//	Country *ptr = temp[count.getCountryName()];
			//	isValid = worldMap.ifConnectedGraph(ptr);
			//	//cout << "FIRST check : This map is " << (isValid ? "valid" : "invalid" ) << ". Countries are connected..." << endl;
			//	//isValid = worldMap.ifConnectedContinent(worldMap.getWorldMap()[count.getCountryName()], worldMap.getWorldMap()[count.getCountryName()] -> getContinent());
			//	//cout << "SECOND check : This map is " << (isValid ? "valid" : "invalid") << ". Continents are connected..." << endl;
			//	}
			//	catch (exception e) {
			//		cout << isValid << endl;
			//	}
			//	
			//}

		} 

	}
	else
		cout << "File is not open.";

	ifs.close();
	system("pause");

}