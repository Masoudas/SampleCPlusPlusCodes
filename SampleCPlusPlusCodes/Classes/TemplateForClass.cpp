#include "TemplatesForClass.h"

template <class T> ClassWithTemp<T>::ClassWithTemp(T temp) {
	this->temp = temp;
}

template <class T> void ClassWithTemp<T>::returnVal(T temp) {
	std::cout << temp;
}