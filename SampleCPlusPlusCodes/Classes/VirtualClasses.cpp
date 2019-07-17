#include "VirtualClasses.h"

void TestVirtualMethods(void) {
	Derived1 derived1{};
	Derived2 derived2{};
	Derived3 derived3{};

	derived1.print();
	derived2.print();
	derived3.print();

	Base* ptr[4] = { new Base{}, &derived1,&derived2,&derived3 }; // Now that we have the pointer, 
																	// again the overriden method (if it exists) will be executed.
	ptr[0]->print();
	ptr[1]->print();
	ptr[2]->print();
	ptr[3]->print();

}