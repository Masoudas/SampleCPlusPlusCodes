#ifndef __Fundamentals_H__
#define __Fundamentals_H__
#include <string>
#include <iostream>
using namespace std;
class MyClass
{
public:
	static int staticParam; // Static members, can be accessed via instances of class, or through the class identifier itself.
	int val = 10;
	int* ptr = &val;
	std::string str = "This string is shallow copied";
	int arr[2] = { 1, 2 };

	MyClass(int, int);	// As soon as you define a constructure, the class does not have the default class anymore. So, 
						// in that case make sure to put the default constructure there.
	MyClass() { std::cout << "Inside the base class" << std::endl; };
					// Each class by default has a default constructure, which accepts the instance of the class and performs a shallow copy
					// of it, unless overridden.
	MyClass(double, double);
	~MyClass() { cout << "PEACE" << endl; }; // Finalizers cannot be inherited.
			  	   // When pointer is allocated inside the class, it should be deleted in destructure.
				   // Also, see this interesting question. https://www.geeksforgeeks.org/playing-with-destructors-in-c/
				   // Note that the destructure is called after the entire block containing the class instance is finished.
				   // Destructures and constructures can be private.
				   // We may explicitly delete an object. In that case, the destructure is called as well.

	void calculateArea(void);

private:
	int width=5, length=4;
	void print(int);

};


#endif // !__Fundamentals_H__
