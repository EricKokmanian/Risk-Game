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
		cout << " =================== ATTACK PHASE IS STARTING ================== \n" << endl;
		cout << attackPhase->getAttacker()->getName() << " IS STARTING TO ATTACK.\n" << endl;
	}

}