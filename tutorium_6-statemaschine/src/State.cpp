/*
 * @file    State.cpp
 * @author  Simon Brummer
 * @desc    Tutorium 6. State ist DIE Oberklasse der Statemaschine.
 *          Sie implementiert alle Methoden des "Transitions" Interfaces. 
 *          Diese Methoden sind die Transitionen der Statemaschine und 
 *          koennen Zustandsuebergaengen fuehren.
 */
#ifndef STATE_CPP_
#define STATE_CPP_

#include "Transitions.h"
#include "Context.cpp"
#include "Dispatcher.cpp"

using namespace std;

class State: public Transitions {
protected:
	Context* con_;

public:
	State(Context* con): con_(con){
		cout << "State(Context* con)" << endl;
	}

	virtual ~State(){
		cout << "~State()" << endl;
	}

    virtual void Transition1(void){
    	cout << "State::Transition1" << endl;
    }

    virtual void Transition2(void){
    	cout << "State::Transition2" << endl;
    }
    virtual void Transition3(void){
    	cout << "State::Transition3" << endl;
    }

private:
    State(const State& other);
    State& operator=(const State& other);
};

#endif /* STATE_H_ */









