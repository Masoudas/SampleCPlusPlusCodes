#include <iostream>
#include "Classes/Fundamentals.h"
#include "Classes/DuplicateClass.h"
#include "Classes/OperatorOverload.h"
#include "Classes/ConstantInstantiation.h"
#include "Classes/Assignment.h"
using namespace std;

void main(void) {
	MyClass* classPtr = new MyClass;
	cout << "Something1";
	delete classPtr;

	cout << "Something";

}