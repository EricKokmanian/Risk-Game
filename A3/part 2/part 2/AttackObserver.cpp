#include "AttackObserver.h"

using namespace std;

AttackObserver::AttackObserver() {

}

AttackObserver::AttackObserver(AttackPhase* attackPhase) {
	this->attackPhase = attackPhase;
	attackPhase->Attach(this);
}

AttackObserver::~AttackObserver() {
	attackPhase->Detach(this);
}

void AttackObserver::Update() {
	display();
}

void AttackObserver::display() {
	if (attackPhase->keepAttacking) {
		cout << " ========================== ATTACK PHASE ========================= \n" << endl;
		cout << "ATTACKER: " << attackPhase->getAttacker()->getName() << endl;
		cout << "Countries owned: " << endl;
		for (auto it = attackPhase->getAttacker()->getCountries().begin(); it != attackPhase->getAttacker()->getCountries().end(); ++it) {
			cout << "- " << (*it)->getCountryName() << " with " << (*it)->getArmyNumber() << " armies." << endl;
		}
		if (attackPhase->getDefender() != NULL) {
			cout << "\nDEFENDER: " << attackPhase->getDefender()->getName() << endl;
			cout << "Countries owned: " << endl;
			for (auto it = attackPhase->getDefender()->getCountries().begin(); it != attackPhase->getDefender()->getCountries().end(); ++it) {
				cout << "- " << (*it)->getCountryName() << " with " << (*it)->getArmyNumber() << " armies." << endl;
			}
		}
		cout << " ========================== ATTACK PHASE ========================= \n" << endl;

	}

}