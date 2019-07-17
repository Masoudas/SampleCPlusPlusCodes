#include "Inheritance.h"

void TestInvocationOfConstructors(void) {
	DerivedClass derivedClass();
	DerivedClass derivedClass1{ 5, 5, 5 };
}

DerivedClass::DerivedClass(int derivedClassVal, int width, int length) : MyClass(width, length) {
	this->derivedClassVal = derivedClassVal;
	std::cout << "Inside the constructor of the derived class with one integers" << std::endl;
}

void Assignment(void) {
	DerivedClass derivedClass{ 15, 15, 15 };
	DerivedClass derivedClass1{ 5, 5, 5 };
	MyClass myClass{ 10, 10 };

	myClass = derivedClass1;	// So apparently this assignment is acceptable. Then the fields of base class would be equal to that of derived class.
	std::cout << myClass.val << std::endl;

	// derivedClass = myClass; // Well, it makes sense that this operator is not accepatable, because the derived class has fields that are
							   // not inside the base class.


	// Now suppose that we want to keep an array of different objects, all of which derived from the same base class. What we can do here
	// is that we define an array of POINTERS from the base class, and we are good to go. The only point we should remember here is that this array would
	// only have access to the elements of the base class.
	MyClass* arr[2] = { &derivedClass, &derivedClass1 };
	arr[0]->calculateArea();
	arr[1]->calculateArea();
	arr[0]->arr[0] = 1000;	// Changing the content of the arr in the derived class here.


	// The interesting part is that we can still use the information inside the derived class.
	std::cout << "Accessing element changed through base class pointer: " << derivedClass.arr[0] << std::endl;


	// Note that the following is completely different. We are actually creating new objects down here, because each space in arr opens up a memory space
	// so when we put an instance of the DerivedClass, we would actually create a new object here.
	MyClass arr1[2] = { derivedClass, derivedClass1 };
	arr1[0].arr[0] = 500;	// Changing the content of the arr in the derived class here. But notice that in the following line,
							// the content of derivedClass is not changed.
	std::cout << "Content without the use of pointer for the array has not changed: " << derivedClass.arr[0] << std::endl;

	// Now the question is, how can we perhaps manipulate and see the elements of the derived class from the pointer of the base class.
	// First method is of course to use virtual methods. Virtual methods allow access to the last place where the thing is defined.
	// We can also use the visitor pattern, together with the virtual methods.
	// The visitor pattern allows to add methods for (some) classes of an object structure without changing the classes.

}
