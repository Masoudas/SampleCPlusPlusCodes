#include <iostream.h>
// First, note that exceptions are responses to run-time problems.
// Exceptions provide a way to transfer control from one part of a program to another. 
// C++ exception handling is built upon three keywords: try, catch, and throw.
// throw: A program throws an exception when a problem shows up. This is done using a throw keyword.
// catch: A program catches an exception with an exception handler at the place in a program where you want to handle the problem.
//        The catch keyword indicates the catching of an exception.
// try: A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.

using namespace std;



void fundamentals(void) {
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