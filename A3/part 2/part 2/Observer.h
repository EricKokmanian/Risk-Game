#pragma once
using namespace std;

class Observer {
	public:
		~Observer();
		virtual void Update() = 0;

	protected:
		Observer();
};