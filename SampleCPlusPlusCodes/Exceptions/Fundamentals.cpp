#include <iostream>

// First, note that exceptions are responses to run-time problems.
// Exceptions provide a way to transfer control from one part of a program to another. 
// C++ exception handling is built upon three keywords: try, catch, and throw.
// throw: A program throws an exception when a problem shows up. This is done using a throw keyword.
// catch: A program catches an exception with an exception handler at the place in a program where you want to handle the problem.
//        The catch keyword indicates the catching of an exception.
// try: A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.

using namespace std;



void fundamentals(int input) {
	try { // Try is the block in which we want to catch the exception.
		if (input > 10 && input < 20) {
			throw 10; // Here we throw an exception. By throwing an integer, we are just throwing a random number here, which 
					// indicates what should be caught by the catch part.
		}
		else if (input > 20 && input < 30) {
			throw 'a';
		}
		
	}
	catch (int e) {
		cout << "Catching exception of integer type " << e << endl;
	}
	catch (char e) {
		cout << "Catching exception of char type " << e << endl;
	}

	try { 
		throw 'a';
	}
	catch (...) {	// When the three dots are placed here, no matter what the type is, it is caught here.
		cout << "Catching whatever type of exception we have" << endl;
	}

}

// The most important point is that an exception must be handled, somewhere. not necessarily inside the same block.
// Consider the following example. We see that the exception is caught in the catchException method.

void division(int a, int b) {
	if (a == 0) {
		throw "Division by zero";
	}
}

void catchException() {
	try {
		division(0, 1);
	}
	catch (const char* e) {
		cout << e << endl; // The error is gracefully handled here.
	}

	cout << "The program continues after the exception is thrown";
}