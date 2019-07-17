#ifndef __VIRTUAL_CLASSES_H__
#define __VIRTUAL_CLASSES_H__

#include <iostream>
using namespace std;

// What is the difference between declaring a method virtual and simply writing over it?

class Base {
public:
	virtual void print(void) {
		cout << "Virtual method of the base class" << endl;
	};

	void methodNotVirtual(void) {
		cout << "Non-Virtual method of the base class" << endl;
	}
};

class Derived1: public Base {
public:
	void print(void) {	
		// Overriding the virtual method.
		cout << "Virtual method of the derived1 class" << endl;
	};

	void methodNotVirtual(void) {
		// Now this method covers the method of base
		cout << "Non-Virtual method of the derived1 class" << endl;
	}

};

class Derived2 : public Derived1 {
	// The virtual method is not overriden here.
};

class Derived3 : public Derived2 {
public:
	void print(void) {
		// Overriding the virtual method.
		cout << "Virtual method of the derived3 class" << endl;
	};

	void methodNotVirtual(void) {
		// Now this method covers the method of base
		cout << "Non-Virtual method of the derived3 class" << endl;
	}

};

#endif // !__VIRTUAL_CLASSES_H__
