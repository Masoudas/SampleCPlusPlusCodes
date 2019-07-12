#include <iostream>
#include "Classes/Fundamentals.h"

#include "Classes/OperatorOverload.h"

using namespace std;

void main(void) {
	MyClass myClass(5, 2);
	myClass.calculateArea();
	myClass.~MyClass();

	MyClass myClass1{};
	myClass1 = myClass1;
	myClass.val = 20;

	cout << myClass1.val << endl;

	MyClass myClass2{ 10, 5 };
	myClass2.calculateArea();

	OverloadPlusSign overloadPlusSign{30};
	OverloadPlusSign overloadPlusSign1{ 20 };

	overloadPlusSign1 = overloadPlusSign1 + overloadPlusSign;
	cout << overloadPlusSign1.val << endl;

	overloadPlusSign1 += overloadPlusSign;
	cout << overloadPlusSign1.val << endl;

	
}