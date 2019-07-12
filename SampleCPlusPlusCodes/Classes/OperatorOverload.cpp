#include "OperatorOverload.h"
#include <iostream>
using namespace std;

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
