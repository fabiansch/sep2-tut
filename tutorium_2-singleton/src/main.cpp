/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.3
 * @desc    Singleton example implementations:
 *          - Gov Singleton
 *          - Meyers Singleton
 *          - DCLP Singleton
 */

#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;

/* Begin GOVSingleton */
// Declaration
class GOFSingleton {
private:
    static GOFSingleton* instance_;

private:
    GOFSingleton();
	GOFSingleton(const GOFSingleton& other);
	GOFSingleton& operator=(const GOFSingleton& other);
	~GOFSingleton();

public:
    static GOFSingleton* getInstance();
	void method(void);
};

// Implementation
GOFSingleton* GOFSingleton::instance_ = NULL;

GOFSingleton* GOFSingleton::getInstance(){
	if( instance_ == NULL){
		instance_ = new GOFSingleton();
	}
	return instance_;
}

GOFSingleton::GOFSingleton(){
	cout << "ctor GOF Singleton" << endl;
}

GOFSingleton::~GOFSingleton(){
	cout << "dtor GOF Singleton" << endl;
}

void GOFSingleton::method(){
	cout << "method called" << endl;
}
/* End GOV-Singleton */


/* Begin Meyers-Singleton */
// Declaration
class MeyersSingleton {
private:
    MeyersSingleton();
    MeyersSingleton(const MeyersSingleton& other);
    MeyersSingleton& operator=(const MeyersSingleton& other);
    ~MeyersSingleton();

public:
    static MeyersSingleton* getInstance();
    void method(void);
};

// Implementation
MeyersSingleton* MeyersSingleton::getInstance(){
	static MeyersSingleton instance;
	return &instance;
}

MeyersSingleton::MeyersSingleton(){
	cout << "ctor Meyers Singleton" << endl;
}

MeyersSingleton::~MeyersSingleton(){
	cout << "dtor Meyers Singleton" << endl;
}

void MeyersSingleton::method(){
	cout << "method called" << endl;
}
/* End Meyers-Singleton */


/* Begin DCLP-Singleton */
// Declaration
class DCLPSingleton {
private:
    static DCLPSingleton* instance_;

private:
    DCLPSingleton();
    DCLPSingleton(const DCLPSingleton& other);
    DCLPSingleton& operator=(const DCLPSingleton& other);
    virtual ~DCLPSingleton();

public:
    static DCLPSingleton* getInstance();
    void method(void);
};

// Implementation
DCLPSingleton* DCLPSingleton::instance_ = NULL;

DCLPSingleton* DCLPSingleton::getInstance(){
	static pthread_mutex_t mtx_ = PTHREAD_MUTEX_INITIALIZER;

	if( instance_ == NULL){
		pthread_mutex_lock(&mtx_);
		if( instance_ == NULL){
		    instance_ = new DCLPSingleton();
		}
		pthread_mutex_unlock(&mtx_);
	}
	return instance_;
}

DCLPSingleton::DCLPSingleton(){
	cout << "ctor DCLP Singleton" << endl;
}

DCLPSingleton::~DCLPSingleton(){
	cout << "dtor DCLP Singleton" << endl;
}

void DCLPSingleton::method(){
	cout << "method called" << endl;
}
/* End DCLP Singleton */


// Main Function and Demo Code
int main() {
	GOFSingleton*    gov  = GOFSingleton::getInstance();
	MeyersSingleton* mey  = MeyersSingleton::getInstance();
	DCLPSingleton*   dclp = DCLPSingleton::getInstance();

	gov->method();
	mey->method();
	dclp->method();

	return 0;
}
