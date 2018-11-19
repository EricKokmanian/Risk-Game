#pragma once
#include <iostream>	
#include "Observer.h"
#include "FortificationPhase.h"

class FortificationObserver : public Observer {

public:
	FortificationObserver();
	FortificationObserver(FortificationPhase*);
	~FortificationObserver();
	void Update();
	void display();

private:
	FortificationPhase* fortificationPhase;
};