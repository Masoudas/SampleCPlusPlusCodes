#include <iostream>

int add(int x, int y) {
	return x + y;
}

int subtract(int x, int y) {
	return x - y;
}

void choiceOfMethod(int (*funToCall)(int, int), int x, int y) {
	std::cout << funToCall(x, y) << "\n";

}

void passMethod(void) {
	int x = 10;

	choiceOfMethod(add, x, x);
	choiceOfMethod(subtract, x, x);
}
