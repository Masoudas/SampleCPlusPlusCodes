#include <iostream>

union MyUnion
{
	int x;
	float y;
	double z;
};

void Fundamentals(void) {
	/* The catch of the unions is that every instance of my union either holds an int, float or double. So we can't value all three
	simultaneously. Hence if we run the following code, we see that the only member of the union that has a value is z.*/
	MyUnion myUnion;
	myUnion.x = 10;
	myUnion.y = 10.1f;
	myUnion.z = 10.11;

	std::cout << myUnion.x;
	std::cout << myUnion.y;
	std::cout << myUnion.z;
}