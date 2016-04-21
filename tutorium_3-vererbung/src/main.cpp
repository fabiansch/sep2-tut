/*
 * @file    main.cpp
 * @author  Simon Brummer
 * @version 0.2
 * @desc    Tutorium 3. Vererbung, dynamische Bindung und Keyword virtual.
 *          Aufrufen der Methoden einer Superklasse(wg. moeglicher Mehrfachvererbung)
 */

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/* Implementation Superclass */
class Super_Class{
  private:
	int super_int_;

  public:
	Super_Class(): super_int_(0){
		cout << "Super_Class()" << endl;
	}

	Super_Class(int i): super_int_(i){
		cout << "Super_Class(int)" << endl;
	}

	Super_Class(const Super_Class& other): super_int_(other.super_int_){
		cout << "Super_Class(const Super_Class&)" << endl;
	}

	Super_Class& operator=(const Super_Class& other){
		cout << "Super_Class& operator=(const Super_Class&)" << endl;
		if( this != &other){
			super_int_ = other.super_int_;
		}
		return *this;
	}

	virtual ~Super_Class(){
		cout << "~Super_Class()" << endl;
	}

	string to_string_non_virtual(void) const {
		ostringstream os;
		os << "[Super_Class: super_int_=" << super_int_ << "]";
		return os.str();
	}

	virtual string to_string_virtual(void) const {
		ostringstream os;
		os << "[Super_Class: super_int_=" << super_int_ << "]";
		return os.str();
	}
};

/* Implementation Inherited Class */
class Base_Class: public Super_Class{
  private:
	int base_int_;

  public:
	Base_Class(): base_int_(0){
		cout << "Base_Class()" << endl;
	}

	Base_Class(int super_int): Super_Class(super_int), base_int_(0){
		cout << "Base_Class(int)" << endl;
	}

	Base_Class(int super_int, int base_int): Super_Class(super_int), base_int_(base_int){
		cout << "Base_Class(int,int)" << endl;
	}

	Base_Class(const Base_Class& other): Super_Class(other), base_int_(other.base_int_) {
		cout << "Base_Class(const Base_Class&)" << endl;
	}

	Base_Class& operator=(const Base_Class& other){
		cout << "Base_Class& operator=(const Base_Class&)" << endl;
		if( this != &other){
			Super_Class::operator=(other);
			base_int_ = other.base_int_;
		}
		return *this;
	}

	virtual ~Base_Class(){
		cout << "~Base_Class()" << endl;
	}

	string to_string_non_virtual(void) const {
		ostringstream os;
		os << "[Base_Class: base_int_=" << base_int_ << Super_Class::to_string_non_virtual() <<"]";
		return os.str();
	}

	virtual string to_string_virtual(void) const {
		ostringstream os;
		os << "[Base_Class: base_int_=" << base_int_ << Super_Class::to_string_virtual() <<"]";
		return os.str();
	}
};

/* Main Function */
int main(int argc, char** args){
	// Hier nur heap allokierte Objekte, da es bei stackallokierten
	// Objekten keine dynamische Bindung gibt bzw. nicht formulierbar ist.

	cout << "Konstruktoren Aufrufe" << endl;
	Super_Class* super = new Super_Class(1);
	Super_Class* base  = new Base_Class(1,2);

	cout << "\n\nVirtuelle Funktionen" << endl;
	cout << super->to_string_virtual() << endl;
	cout << base->to_string_virtual() << endl;

	cout << "\n\nNicht - Virtuelle Funktionen" << endl;
	cout << super->to_string_non_virtual() << endl;
	cout << base->to_string_non_virtual() << endl;

	cout << "\n\nDestruktoren Aufrufe" << endl;
	delete base;
	delete super;

	return 0;
}
