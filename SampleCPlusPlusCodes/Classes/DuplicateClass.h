#ifndef __DUPLICATE_CLASS_H__
#define __DUPLICATE_CLASS_H__
// This class has a duplicate name as the class in fundamentals. So what happens when we call it together 
// with the fundamentals header? The last inclusion is apparently considered as the definition.
// In this case perhaps what we can do is to define name spaces.
// Name spaces can be defined uncontigously (meaning being extended among several files), they can
// also, they they can be nested.

namespace Classes {
	class MyClass {
	public:
		int duplicate = 10;
	};
}
#endif // !__DUPLICATE_CLASS_H__
