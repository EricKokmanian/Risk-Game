#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
	//srand(time(0));
	using namespace std;
	Dice d;

	vector<int> vect1;
	vector<int> vect2;
	vect1 = d.roll(2);
	for (int i : vect1)
	{
		cout << i << " ";
	}
	system("pause");

	vect2 = d.roll(1);
	for (int i : vect2)
	{
		cout << i << " ";
	}
	system("pause");

	vect2 = d.roll(3);
	for (int i : vect2)
	{
		cout << i << " ";
	}
	system("pause");
	vect2 = d.roll(3);
	for (int i : vect2)
	{
		cout << i << " ";
	}
	system("pause");
	vect2 = d.roll(3);
	for (int i : vect2)
	{
		cout << i << " ";
	}
	system("pause");
	vect2 = d.roll(3);
	for (int i : vect2)
	{
		cout << i << " ";
	}
	system("pause");

	cout << d.getPerc(2) <<" % " << endl;
	system("pause");
	cout << d.getPerc(3) << " % " << endl;
	system("pause");
	vector<float> percVect = d.getPer();
	for (float i : percVect)
	{
		cout << i << " % ";
	}
	system("pause");
	return 0;
}