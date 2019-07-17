#ifndef __ABSTRACT_CLASS_H__
#define __ABSTRACT_CLASS_H__

#include <iostream>
using namespace std;
// A class is considered abstract, when there's a virtual method inside of it which has no body and set to zero.

class Abstract {
public:
	int var = 10;
	Abstract() {}; // We cannot declate constructor abstract, mostly because suppose the virtual constructor of the top class is not overriden.
				   // Then when we invoke the constructor in the derived class, the compiler would not be aware whether it should create an
				   // instance of the derived class or the base class.

	virtual void print() = 0;	// So this is the abstract class, cannot be instantiated.
};

class Implementation1 : public Abstract {
public:
	virtual void print() { cout << "The abstract class is implemented here"; };	// So this is the abstract class, cannot be instantiated.

};
#endif // !__ABSTRACT_CLASS_H__
