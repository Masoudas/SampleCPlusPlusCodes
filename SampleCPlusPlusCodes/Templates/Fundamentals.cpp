#include <iostream>

// So, what is the difference when we say typename and class when we define a template?
// No difference, apparently writing <class T> was the older method.

template<typename T> class Vector {
//template<class T> class Vector {
public:
	explicit Vector(int s) {
		//if (s < 0) throw Negative_size{};
		sz = s;
		elem = new T[s];
	}

	T& operator[](int i) {
		//if (i >= sz || i < sz) throw Out_of_Range{};
		return elem[i];

	}

	const T& operator[](int i) const {
		// The constant written here at the end has a couple of uses:
		// 1- When the instantiated class is constant, this method is invoked.
		// 2- When declaring it, we give the promise not to alter the internal state of the class, though we can.
		
		//if (i >= sz || i < sz) throw Out_of_Range{};
		elem[i] = 5; //Because we added the const at the end of the function definition, we are not supposed to do this, but we can! This is because 
					// the elem is not constant by itself.
					// What's interesting is that if during instantiation I use const, then I would not be able to change this parameter from
					// outside of the class, whereas it is possible from the inside!
		return elem[i];
	}

private:
	T* elem;
	int sz;

};

void invokeTemplateClass(void) {
	const Vector<double> vec(5);
	std::cout << vec[2];

	Vector <int[5]> vec1(2);	// Ok!
}

