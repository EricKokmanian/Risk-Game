#pragma once
#include <iostream>	
#include "Observer.h"
#include "Driver.h"

class ReinforcementObserver : public Observer {
public:
	ReinforcementObserver();
	ReinforcementObserver(Driver*);
	~ReinforcementObserver();
	void Update();
	void display();

private:
	Driver* reinforcementPhase;
};