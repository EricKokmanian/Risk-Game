#include "Graph.h"
#include "Map.h"
#include <iostream>
#include <string>
using namespace std;

Graph::Graph()
{
}

Graph::Graph(Map * m)
{
	_subject = m;
	_subject->Attach(this);
}


Graph::~Graph()
{
	_subject->Detach(this);
}

void Graph::Update()
{
	display();
}

//method which displays the stats
void Graph::display()
{
	string name = "";
	double y = 0;
	double total = _subject->getMap().size();
	vector<string> visitedNames;
	cout << endl << "---------------------- MAP STATE VIEW -----------------------" << endl;
	//iterating through countries and calculating percentage ownership
	for (auto& x : _subject->getMap())
	{
		name = x.second->getOwner()->getPlayerName();
		visitedNames.push_back(name);
		for (auto& x : _subject->getMap()) {
			if (x.second->getOwner()->getPlayerName() == name) {
				y += 1;
			}
		}
		int z = 0;

		//checking if we already printed the player's stats
		for (auto i : visitedNames) {
			if (i == name) {
				z++;
			}
		}
		//if not, then print
		if (z < 2 && (y/total) !=0) {
			cout << name << " owns :" << (y / total) * 100 << "% of the world." << endl;
			//checking if someone owns the entire world
			if (y / total == 1) {
				cout << "Congratulations! " << name << " owns the world!" << endl;
			}
		}
		y = 0;
	}
	cout << "--------------------------------------------------------" << endl << endl;
}
