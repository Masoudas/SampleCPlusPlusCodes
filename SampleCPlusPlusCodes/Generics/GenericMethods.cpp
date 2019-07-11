#include <iostream>

/* For cases where similair operation is performed with different function inputs, 
	C++ has the ability to define functions with generic types, known as function templates. 
	Defining a function template follows the same syntax as a regular function, 
	except that it is preceded by the template keyword and a series of template parameters enclosed in angle-brackets <>:*/

template <class T> // Here it means all in put parameters are of the same type, so one cannot be int and the other one double
T sum(T t, T u) {
	return t + u;
}

template <class T, class U> // Here the two inputs can be of different types.
T diff(T t, U u) {
	return t + u;
}

void GenericMethods(void) {
	std::cout << sum(1, 2);
	std::cout << sum(1.2, 2.2);
	std::cout << sum((short)1, (short)2.2);

	std::cout << diff(1.1, 2);

	// This is a more proper way of using template methods.
	std::cout << <int>sum(1, 2);
	std::cout << <double>sum(1.2, 2.2);
	std::cout << <double, int>diff(1.2, 2);
	std::cout << <int, double>diff(1.2, 2);
}