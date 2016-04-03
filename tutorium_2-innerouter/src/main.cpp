/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.2
 * @desc    Uebung zu Konstruktoren und Speicherallokation nach RIAA.
 *          UML Diagram als PDF im Projektpfad
 */

#include <iostream>
#include <stdio.h>
using namespace std;

/* Usually in .h-File */
class Inner{
public:
	Inner();
	Inner(const Inner& other);
	Inner& operator=(const Inner& other);
	virtual ~Inner();
};

Inner::Inner(){
	cout << "Inner()" << endl;
}
Inner::Inner(const Inner& other){
	cout << "Inner(const Inner& other)" << endl;
}
Inner& Inner::operator=(const Inner& other){
	cout << "operator(const Inner& other)" << endl;
	return *this;
}
Inner::~Inner(){
	cout << "~Inner()" << endl;
}


class Outer{
private:
	Inner* inner;

public:
	Outer();
	Outer(const Outer& other);
	Outer& operator=(const Outer& other);
	virtual ~Outer();
};

Outer::Outer(){
	cout << "Outer()" << endl;
	inner = new Inner();
}

Outer::Outer(const Outer& other){
	cout << "Outer(const Outer& other)" << endl;
	inner = new Inner( *(other.inner) );
}

Outer& Outer::operator=(const Outer& other){
	cout << "operator=(const Outer& other)" << endl;
	if(this != &other){
		delete inner;
		inner = new Inner( *(other.inner) ); // Deep Copy
	}
	return *this;
}

Outer::~Outer(){
	delete inner;
	cout << "~Outer()" << endl;
}

// Democode
void call_by_val(Outer a){
	cout << "call_by_val(Outer a)" << endl;
}

void call_by_ref(Outer& a){
	cout << "call_by_ref(Outer& a)" << endl;
}

int main() {
	Outer a;
	Outer b;

	cout << "\n--Before call_by_val(Outer a) " << endl;
	call_by_val(a);
	cout << "\n--Before call_by_ref(Outer& a) " << endl;
	call_by_ref(a);
	cout << "\n--Before operator= " << endl;
	a = b;
	cout << "\n--Before Stack Cleanup" << endl;

	return 0;
}
