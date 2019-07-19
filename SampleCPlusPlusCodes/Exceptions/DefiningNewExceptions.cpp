// What does it mean to define new excpetions? It means to extend the class definition of exception. Then 
// we can have a method that prints the exception message.

#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
	const char* what() const throw () {
		// The throw() part does what?
		return "C++ Exception";
	}
};

