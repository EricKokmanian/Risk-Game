#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Dice
{
public:
	Dice();
	vector<int> roll(int x);
	int getNum() const;
	vector<float> getPer();
	float getPerc(int n);

private:
	int numRoll;
	static float timesRolled;
	static float num1;
	static float num2;
	static float num3;
	static float num4;
	static float num5;
	static float num6;
};