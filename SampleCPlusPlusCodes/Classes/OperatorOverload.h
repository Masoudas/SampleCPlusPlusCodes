#ifndef __OperatorOverload_H__
#define __OperatorOverload_H__
// See the following pages to understand how to override unary operators, binary operators, and relational operators.
class OverloadPlusSign
{
public:
	int val = 10;
	OverloadPlusSign(int);

	OverloadPlusSign operator+(const OverloadPlusSign& class1);
	void operator+=(const OverloadPlusSign& class1); // Does not return a value.
	void operator++(); // This is fascinating. When we define this operator, it implies ++obj. See next line now. What's the difference?
	void operator++(int); // This one implies obj++. Why such a definition? 
						// it allows addition by integer too, i.e OverloadPlusSign = OverloadPlusSign + 5.

};

#endif // !__OperatorOverload_H__
