#pragma once
#include <iostream>	
#include "Observer.h"
#include "AttackPhase.h"

class AttackObserver : public Observer {

public:
	AttackObserver();
	AttackObserver(AttackPhase*);
	~AttackObserver();
	void Update();
	void display();

private:
	AttackPhase* attackPhase;
};