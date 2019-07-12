#ifndef __TEMPLATE_FOR_CLASS_H__
#define __TEMPLATE_FOR_CLASS_H__

#include <iostream>

template <class T>
class ClassWithTemp {
public:
	T temp;

	ClassWithTemp(T temp);
	void print() { std::cout << T; };
	void returnVal(T temp);


}; 

#endif // !__TEMPLATE_FOR_CLASS_H__
