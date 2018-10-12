#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Country.h"
#include "Player.h"
#include "Continent.h"
#include "Map.h"

const vector<string> explode(const string& s, const char& c)
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

	Map worldMap;

	Player p1("Tom");
	Player p2("Jerry");

	Country c;
	Country c2;
	Country c3;

	Continent cont;
	cont.setContName("North America");

	c.setCountryName("Canada");
	c.setOwner(&p1);
	c.setArmyNumber(3);
	c.setContinent(&cont);

	c2.setCountryName("USA");
	c2.setOwner(&p2);
	c2.setArmyNumber(4);
	c2.setContinent(&cont);

	cout << c.getCountryName() << " belongs to " << c.getOwner()->getPlayer() << " and has an army of " << c.getArmyNumber() << endl;

	c.setOwner(&p2);

	cout << c.getCountryName() << " belongs to " << c.getOwner()->getPlayer() << " and has an army of " << c.getArmyNumber() << endl;

	ifstream ifs;
	string firstLine;
	string contName;
	string continent;
	Continent newContinent;
	string terrName;

	vector<string> vect;

	// Opening map file
	ifs.open("map.txt");

	if (ifs.is_open()) {
		while (!ifs.eof() && firstLine != "[Continents]") {
			firstLine.clear();
			getline(ifs, firstLine, '\n');
			cout << firstLine << endl;

		}

		// Work with the continents
		while (!ifs.eof() && contName != "[Territories]") {
			contName.clear();
			getline(ifs, contName, '\n');
			cout << contName << endl;
			continent = contName.substr(0, contName.size() - 2); // Select Continent Name
			newContinent.setContName(continent); // Instantiate new continents

			//cout << contName.substr(contName.size() - 1, contName.size()) << endl; // Select Continent Bonus Pts
		}


		// Work with the territories
		//while (! ifs.eof()) {
		terrName.clear();
		getline(ifs, terrName, '\n');
		cout << terrName << endl;

		vector<string> vect1{ explode(terrName,',') };


		for (int i = 0; i < vect1.size(); i++)
			cout << vect1.at(i) << endl;
		//}
	}
	else
		cout << "File is not open.";

	ifs.close();
	system("pause");

}