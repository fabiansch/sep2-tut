/*
 * @file    State.cpp
 * @author  Simon Brummer
 * @desc    State ist DIE Oberklasse fuer die kuenftige Statemaschine(Tutorium_6).
 *          Sie implementiert alle Methoden des "Transitions" Interfaces. Diese Methoden
 *          werden spaeter die Transitionen der Statemaschine sein und zu Zustandsuebergaengen fuehren.
 */
#ifndef STATE_CPP_
#define STATE_CPP_

#include "Transitions.h"
#include <iostream>
#include <string>
using namespace std;

class State: public Transitions {
private:
	const string name_;

public:
	State(string name): name_(name){
		cout << "State(string name)" << endl;
	}
	virtual ~State(){
		cout << "~State()" << endl;
	}
    virtual void Transition1(void){
    	cout << "State=" << name_.c_str() << " Method=Transition1" << endl;
    }
    virtual void Transition2(void){
    	cout << "State=" << name_.c_str() << " Method=Transition2" << endl;
    }
    virtual void Transition3(void){
    	cout << "State=" << name_.c_str() << " Method=Transition3" << endl;
    }
};

#endif /* STATE_H_ */
