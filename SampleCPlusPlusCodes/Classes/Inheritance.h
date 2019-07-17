#ifndef __INHERITANCE__H__
#define __INHERITANCE__H__

#include "Fundamentals.h"
#include <iostream>

class DerivedClass : public MyClass { // So when the base class is declared public, all the base class members will be inherited with the same 
				// level of access. If for example we call protected, the public members of the base class would become protected, the protected 
				// become protected as well. If private, every member is inherited as private. NEVER USE THIS.
				// 
public:
	// If we inherit a class from another classand create an object of the derived class, 
	// it is clear that the default constructor of the derived class will be invoked, 
	// but before that the default constructor of all of the base classes will be invoked, 
	// i.e the order of invokation is that the base class’s default constructor will be invoked first 
	// and then the derived class’s default constructor will be invoked.
	// Why does this happen? Because we have a derived class, hence the members of the original class are there, and
	// they need to be initialized.
	
	DerivedClass() { std::cout << "Inside the derived class" << std::endl; };
	DerivedClass(int, int, int); // Calling the constructor of the base class is the same as C#. Note that
						 		 // The constructor of the base class is put on the top to indicate that it is always
						 		 // called first.

	int derivedClassVal=10;
	void calculater(void) { this->calculateArea(); };

	~DerivedClass() {
		std::cout << "The destructors are called in the reverse order as the constructors" << std::endl;
	};
};

#endif // !__INHERITANCE__H__
