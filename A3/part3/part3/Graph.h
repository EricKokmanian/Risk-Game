#pragma once
#include "Observer.h"
#include "Map.h"

class Graph : public Observer
{
public:
	Graph();
	Graph(Map* c);
	~Graph();
	void Update();
	void display();
private:
	Map *_subject;
};

