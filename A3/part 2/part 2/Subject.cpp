#include <iostream>
#include "Subject.h"

Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::Attach(Observer* o) {
	observers.push_back(o);
}

void Subject::Detach(Observer* o) {
	observers.remove(o);
}

void Subject::Notify() {
	for (auto it = observers.begin(); it != observers.end(); ++it) {
		(*it).Update();
	}
}