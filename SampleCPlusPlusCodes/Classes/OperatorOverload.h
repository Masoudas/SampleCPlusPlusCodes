#ifndef __OperatorOverload_H__
#define __OperatorOverload_H__
class OverloadPlusSign
{
public:
	int val = 10;
	OverloadPlusSign(int);

	OverloadPlusSign operator+(const OverloadPlusSign& class1);
	void operator+=(const OverloadPlusSign& class1); // Does not return a value.

};


#endif // !__OperatorOverload_H__
