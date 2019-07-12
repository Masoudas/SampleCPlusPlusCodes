#include "TemplatesForClass.h"

template <class T> // The identifier should be present when defining the class in a separate file.
ClassWithTemp<T>::ClassWithTemp(T temp) {
	this->temp = temp;
}

template <class T> // the identifier should be present when defining the class in a separate file.
void ClassWithTemp<T>::returnVal(T temp) {
	std::cout << temp;
}