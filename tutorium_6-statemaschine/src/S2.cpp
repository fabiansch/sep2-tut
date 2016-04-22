/*
 * @file    S2.cpp
 * @author  Simon Brummer
 * @desc    Tutorium 6. Implementierung von State S2.
 *          Wechselt bei TRANSITION1 nach S2. Bleibt bei TRANSITION2 in S2.
 */
#include "S1.h"
#include "S2.h"
#include "Dispatcher.cpp"
#include <new>

S2::S2(Context* con): State::State(con){
	cout << "S2()" << endl;

	// Start listen on Event Transition1 and Event Transmission2
	Dispatcher* dsp = Dispatcher::getInstance();
	dsp->addListener( this->con_, TRANSITION1);
	dsp->addListener( this->con_, TRANSITION2);
}

S2::~S2(){
	cout << "~S2()" << endl;
}

void S2::Transition1(void){
	cout << "S2 --T1--> S1" << endl;

	// Stop listen to Event Transmission1 and Event Transmission2
	Dispatcher* dsp = Dispatcher::getInstance();
	dsp->remListeners( this->con_, TRANSITION1);
	dsp->remListeners( this->con_, TRANSITION2);

	// Move to State S1.
	new (this) S1(this->con_);
}

void S2::Transition2(void){
	cout << "S2 --T2--> S2" << endl;
}
