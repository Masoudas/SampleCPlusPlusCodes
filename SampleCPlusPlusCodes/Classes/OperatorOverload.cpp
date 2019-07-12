#include "OperatorOverload.h"
#include <iostream>
using namespace std;

//*oid main(void) {
//	OverloadPlusSign overloadPlusSign{ 30 };
//	OverloadPlusSign overloadPlusSign1{ 20 };
//
//	overloadPlusSign1 = overloadPlusSign1 + overloadPlusSign;
//	cout << overloadPlusSign1.val << endl;
//
//	overloadPlusSign1 += overloadPlusSign;
//	cout << overloadPlusSign1.val << endl;
//
//	++overloadPlusSign1;
//	cout << overloadPlusSign1.val << endl;
//
//	overloadPlusSign1++;
//	cout << overloadPlusSign1.val << endl;
//
//	overloadPlusSign1 += 5;
//	cout << overloadPlusSign1.val << endl;
//}*/

OverloadPlusSign::OverloadPlusSign(int val1)
{
	val = val1;
}

OverloadPlusSign OverloadPlusSign::operator+ (const OverloadPlusSign& class1)
{
	OverloadPlusSign overloadPlusSign{val + class1.val};

	return overloadPlusSign;
}

void OverloadPlusSign::operator+= (const OverloadPlusSign& class1)
{
	val += class1.val;
}

void OverloadPlusSign::operator++() {
	val++;
}


void OverloadPlusSign::operator++(int x) {
	val += x;
}