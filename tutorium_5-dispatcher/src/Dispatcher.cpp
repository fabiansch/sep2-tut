/*
 * @file    Dispatcher.cpp
 * @author  Simon Brummer
 * @desc    Der Dispatcher erhaelt Events und ruft bei eintreffen
 *          eines Events, zu zugehoerigen Methoden der Listener auf, die
 *          sich dafuer Registriert haben.
 */
#ifndef DISPATCHER_CPP_
#define DISPATCHER_CPP_

#include "Transitions.h"
#include <iostream>
#include <vector>
using namespace std;

// Events in the System. Each EVENT needs a corresponding Method in class Transactions
enum EVENTS { TRANSITION1, TRANSITION2, TRANSITION3, NEVENTS };

// typedef: Method from Class "Transitions"
typedef void (Transitions::*method_t)(void);

class Dispatcher {
private:
	method_t methods[NEVENTS];
	vector<Transitions *> listeners_[NEVENTS];

public:
	Dispatcher() {
		// Add Method pointer to Call Method Array
		methods[TRANSITION1] = &Transitions::Transition1;
		methods[TRANSITION2] = &Transitions::Transition2;
		methods[TRANSITION3] = &Transitions::Transition3;
	}

	virtual ~Dispatcher() {}

	virtual void addListener(Transitions *listener, EVENTS event) {
		// Add Listener to be called on a specific Event
		listeners_[event].push_back(listener);
	}

	virtual void remListeners(Transitions *listener, EVENTS event) {
		// Remove Listener from a specific Event
		for (unsigned i = 0; i < listeners_[event].size(); ++i) {
			if (listeners_[event][i] == listener){
				listeners_[event].erase(listeners_[event].begin() + i);
			}
		}
	}

	virtual void callListeners(EVENTS event) {
		// Call for every registered Listener
		// the Method that corresponds with event.
		for (unsigned i = 0; i < listeners_[event].size(); ++i) {
			(listeners_[event][i]->*methods[event])();
		}
	}

private:
	Dispatcher(const Dispatcher &other);
	Dispatcher &operator=(const Dispatcher &other);
};

#endif
