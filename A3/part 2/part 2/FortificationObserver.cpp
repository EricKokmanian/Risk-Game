#include "FortificationObserver.h"

using namespace std;

FortificationObserver::FortificationObserver() {

}

FortificationObserver::FortificationObserver(FortificationPhase* fortificationPhase) {
	this->fortificationPhase = fortificationPhase;
	fortificationPhase->Attach(this);
}

FortificationObserver::~FortificationObserver() {
	fortificationPhase->Detach(this);
}

void FortificationObserver::Update() {
	display();
}

void FortificationObserver::display() {
	if (fortificationPhase->fortifying) {
		cout << " ================================ FORTIFICATION PHASE =============================== \n" << endl;
		cout << fortificationPhase->getPlayer()->getName() << " IS STARTING TO FORTIFY.\n" << endl;
		cout << "Countries owned: " << endl;
		for (auto it = fortificationPhase->getPlayer()->getCountries().begin(); it != fortificationPhase->getPlayer()->getCountries().end(); ++it) {
			cout << "- " << (*it)->getCountryName() << " with " << (*it)->getArmyNumber() << " armies." << endl;
		}
		cout << " ================================ FORTIFICATION PHASE =============================== \n" << endl;

	}

}