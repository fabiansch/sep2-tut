//============================================================================
// Name        : tutorium_2-constructors.cpp
// Author      : Simon Brummer
// Description : Constructor Special. Explanation of the "great Three".
//               Difference Call by Value and Call by Reference
//============================================================================
#include <iostream>
using namespace std;

/* Declaration: This goes into usually .h-File */
class Obj{
private:
	string* pName_;

public:
	Obj();                            // Constructor
	Obj(string name);                 // Constructor with Parameter
	Obj(const Obj& other);            // Copy Constructor
	Obj& operator=(const Obj& other); // Assignment Operator
	virtual ~Obj();                   // Destructor
};

/* Implementation: This goes into usually .cpp-File */
// Constructor
Obj::Obj() {
	this->pName_ = new string("NO_NAME");
	cout << "Name: " << *this->pName_ << ", Func: Obj()" << endl;
};

// Constructor with Parameter
Obj::Obj(string name){
	this->pName_ = new string(name);
	cout << "Name: " << *this->pName_ << ", Func: Obj(string name)" << endl;
};

// Copy Constructor
Obj::Obj(const Obj& other){
	this->pName_ = new string( *(other.pName_) );
	cout << "Name: " << *this->pName_ <<", Func: Obj(const Obj& other)" << endl;
};

// Assignment Operator
Obj& Obj::operator=(const Obj& other){
	cout << "Name: " << *this->pName_ << ", Func: operator=(const Obj& other)" << endl;
	if(this != &other){
		delete this->pName_;
		this->pName_ = new string( *(other.pName_) );
	}
	return *this;
};

// Destructor
Obj::~Obj(){
	cout << "Name: " << *this->pName_ << ", Func: ~Obj()" << endl;
	delete this->pName_;
};


/* Demo Code */
// Call by Value: Copy Constructor is called.
void call_by_val(Obj obj){
	cout << "Func: call_by_val(Obj obj)" << endl;
}

// Call by Reference: No Constructor is called
void call_by_ref(Obj& obj){
	cout << "Func: call_by_ref(Obj& obj)" << endl;
}

int main(void) {
	// Constructors
	//Obj no_name;        // Obj() call.
	Obj a("A");         // Obj(string name) call.
	Obj b("B");		  // Obj(string name) call.
	//Obj a_cpy(a);       // Obj(const Obj& other) call. Copy Constructor

	// Assignment
	b.operator =(a);
	b = a;

	// Copy Constructor and Call by Value
	//call_by_val(no_name);
	//call_by_ref(no_name);
	return 0;
}
