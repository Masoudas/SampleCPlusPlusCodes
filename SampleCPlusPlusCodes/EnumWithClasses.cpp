#include <iostream>

// We can define an enumeration inside the class, which will make it accessible from outside the class directly, but not through
// the double column operator, rather with a dot!

class EnumInClass {
public:
	enum {
		yellow,
		brown,
		black,
	};

	// Giving the enumeration a name is not necessary, because no matter what it will be seen from the outside.
	enum other{
		yellow1,
		brown1,
		black1,
	} otherEnum;

	EnumInClass() {
		otherEnum = other::brown1;
	}
};

void invokeClassWithEnum() {
	EnumInClass instance;
	std::cout << instance.black;
	instance.otherEnum = EnumInClass::black1;
}

