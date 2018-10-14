#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Dice.h"

using namespace std;

int main()
{
	//creating a Dice object
	Dice d;

	//creating two vectors to test the roll method
	vector<int> vect1;
	vector<int> vect2;

	//using the roll method on vect1 and rolling 2 times
	vect1 = d.roll(2);
	for (int i : vect1)
	{
		cout << i << " ";
	}
	system("pause");


	//using the roll method on vect2 and rolling 1 time
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

	//Using getPerc() method to get percentage of number 2 with respect to all the rolls so far
	cout << d.getPerc(2) << " % " << endl;
	system("pause");

	//Using getPerc() method to get percentage of number 3 with respect to all the rolls so far
	cout << d.getPerc(3) << " % " << endl;
	system("pause");

	//Creating a new vector to store the output of method getPer() which will return the percentages of all the numbers witrh respect to all the rolls so far
	vector<float> percVect = d.getPer();

	for (float i : percVect)
	{
		cout << i << " % ";
	}
	system("pause");


	return 0;
}