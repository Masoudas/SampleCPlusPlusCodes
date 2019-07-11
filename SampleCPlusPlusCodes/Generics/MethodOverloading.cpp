#include <iostream>

/* So long as the input parameters are different, a function can be overloaded.*/
int add(int x, int y) {
	return x + y;
}

double add(double x, double y) {
	return x + y;
}

double add(double x, double z, double y) {
	return x + y;
}

void MethodOverloading(void) {
	std::cout << add(2, 3);
	std::cout << add(2.1, 3.1);
	std::cout << add(2, 3, 4);
}