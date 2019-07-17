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


void main() {
	int input = 41;

	try { // Try is the block in which we want to catch the exception.
		if (input > 10 && input < 20) {
			throw 10; // Here we throw an exception. By throwing an integer, we are just throwing a random number here, which 
					// indicates what should be caught by the catch part.
		}
		else if (input > 20 && input < 30) {
			throw 'a';
		}
		//throw "An illegal value is given"; // For this third case, we don't have any handlers, so just the message is printed and that's it.
	}
	catch (int e) {
		cout << "Catching exception of integer type " << e << endl;
	}
	catch (char e) {
		cout << "Catching exception of char type " << e << endl;
	}

}