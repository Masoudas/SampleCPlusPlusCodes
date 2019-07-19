#include <iostream>
#include "Classes/DuplicateClass.h"
#include "Classes/OperatorOverload.h"
#include "Classes/ConstantInstantiation.h"
#include "Classes/Fundamentals.h"
#include "Classes/Inheritance.h"
#include "Classes/AbstractClass.h"
#include "Classes/VirtualClasses.h"

#include <iostream>
using namespace std;

void division(int a, int b) {
	if (a == 0) {
		throw "Division by zero";
	}
}

void main() {
	try {
		division(0, 1);
	}
	catch (const char* e) {
		cout << e << endl;
	}

	cout << "The program continues after the exception is thrown";
}