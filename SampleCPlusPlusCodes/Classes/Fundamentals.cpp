#include "Fundamentals.h"
#include <iostream>
using namespace std;
// We can actually call the destructure of the class. Seriously, call it!
// Whoa whoa whoa! This format of instantiating the class "MyClass myClass()" does not call the default constructure. This is 
// interpreted as defining a function called my class that returns MyClass.
// The default is called like this "MyClass myClass". Hence it's always better to instantiate with braces.
//	1- MyClass myClass{}; // Default
//	2- MyClass myClass{width1=10, height1=5}; // Default
// Classes are not referenced type. Hence, direct assignment leads to copying the class. Hence, pass by pointer.
// In the basic notions, classes and structures are the same, except that structure members and methods are 
// by default public, whereas for the class they are by default private.

MyClass::MyClass(int width1, int length1)
{
	width = width1;
	length = length1;
}

MyClass::MyClass(double width1, double length1) : width(width1), length(length1) {}; // Meh. Another way of instantiating a class.


MyClass::~MyClass()
{
	cout << "PEACE" << endl;
}

void MyClass::print(int area) {
	cout << "Area is: " << area << endl;
}

void MyClass::calculateArea(){
	print(2*width + 2* length);
}

