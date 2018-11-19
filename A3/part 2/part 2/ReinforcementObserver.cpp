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
		cout << " =================== REINFORCEMENT PHASE ================== \n" << endl;
		cout << reinforcementPhase->getPlayer()->getName() << " IS REINFORCING.\n" << endl;
		cout << "Countries owned: " << endl;
		for (auto it = reinforcementPhase->getPlayer()->getCountries().begin(); it != reinforcementPhase->getPlayer()->getCountries().end(); ++it) {
			cout << "- " << (*it)->getCountryName() << " with " << (*it)->getArmyNumber() << " armies." << endl;
		}
		cout << " ================== = REINFORCEMENT PHASE ================== \n" << endl;
	}
}