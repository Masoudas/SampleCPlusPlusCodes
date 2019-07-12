#ifndef __Fundamentals_H__
#define __Fundamentals_H__
#include <string>

class MyClass
{
public:
	static int staticParam; // Static members, can be accessed via instances of class, or through the class identifier itself.
	int val = 10;
	int* ptr = &val;
	std::string str = "This string is shallow copied";
	int arr[2] = { 1, 2 };

	MyClass(int, int);
	MyClass(double, double);
	MyClass() { width = 1; length = 5; };
	~MyClass(); // Finalizers cannot be inherited.
			  	   // When pointer is allocated inside the class, it should be deleted in destructure.
				   // Also, see this interesting question. https://www.geeksforgeeks.org/playing-with-destructors-in-c/
				   // Note that the destructure is called after the entire block containing the class instance is finished.
				   // Destructures and constructures can be private.
				   // We may explicitly delete an object. In that case, the destructure is called as well.

	void calculateArea(void);

private:
	int width, length;
	void print(int);

};


#endif // !__Fundamentals_H__
