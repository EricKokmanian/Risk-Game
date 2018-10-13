#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Header.h"

using namespace std;

float Dice::num1;
float Dice::num2;
float Dice::num3;
float Dice::num4;
float Dice::num5;
float Dice::num6;
float Dice::timesRolled;
Dice::Dice()
{
	//numRoll = (rand() % 6) + 1;
	srand(time(0));
	 float timesRolled = 0;
	float num1 = 0;
	 float num2 = 0;
	 float num3 = 0;
	 float num4 = 0;
	 float num5 = 0;
	 float num6 = 0;
}

vector<int> Dice::roll(int x)
{
	if (x < 1 || x>3)
	{
		cout << "Error! invalid number of dice! \n";
		system("pause");
		exit(1);
	}
	vector<int> vect;
	for (int i = 0; i < x; i++)
	{
		int x = (rand() % 6) + 1;
		timesRolled++;
		if (x == 1)
		{
			num1++;
		}
		else if (x == 2)
		{
			num2++;
		}
		else if (x == 3)
		{
			num3++;
		}
		else if (x == 4)
		{
			num4++;
		}
		else if (x == 5)
		{
			num5++;
		}
		else
			num6++;
		vect.push_back(x);
	}
	return vect;
}
int Dice::getNum() const
{
	return numRoll;
}
float Dice::getPerc(int x)
{
	if (timesRolled == 0)
	{
		cout << "Error! you haven't rolled a single tim yet! ";
		exit(0);
	}
	if (x == 1)
	{
		return ((num1 / timesRolled) * 100);
	}
	else if (x == 2)
	{
		return ((num2 / timesRolled) * 100);
	}
	else if (x == 3)
	{
		return ((num3 / timesRolled) * 100);
	}
	else if (x == 4)
	{
		return ((num4 / timesRolled) * 100);
	}
	else if (x == 5)
	{
		return ((num5 / timesRolled) * 100);
	}
	else
		return ((num6 / timesRolled) * 100);

}
vector<float> Dice::getPer()
{
	if (timesRolled == 0)
	{
		cout << "Error! you haven't rolled a single tim yet! ";
		exit(0);
	}
	vector<float> vect;
	vect.push_back((num1 / timesRolled) * 100);
	vect.push_back((num2 / timesRolled) * 100);
	vect.push_back((num3 / timesRolled) * 100);
	vect.push_back((num4 / timesRolled) * 100);
	vect.push_back((num5 / timesRolled) * 100);
	vect.push_back((num6 / timesRolled) * 100);
	
	return vect;
}

