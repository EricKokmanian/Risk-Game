#include "ReinforcementObserver.h"

using namespace std;

ReinforcementObserver::ReinforcementObserver() {

}

ReinforcementObserver::ReinforcementObserver(Driver* reinforcementPhase) {
	this->reinforcementPhase = reinforcementPhase;
	reinforcementPhase->Attach(this);
}

ReinforcementObserver::~ReinforcementObserver() {
	reinforcementPhase->Detach(this);
}

void ReinforcementObserver::Update() {
	display();
}

void ReinforcementObserver::display() {
	if (reinforcementPhase->reinforcing) {
		cout << " =================== REINFORCEMENT PHASE IS STARTING ================== \n" << endl;
		cout << reinforcementPhase->getPlayer()->getName() << " IS STARTING TO REINFORCE.\n" << endl;
	}
}