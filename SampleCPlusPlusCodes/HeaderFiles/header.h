// See also http://www.cplusplus.com/forum/articles/10627/
//==========================================================================
// Including guards
#ifndef __HEADER_H_INCLUDED__	// If this header has not been included, included it, otherwise ignore it.
								// Question. Does it follow the path of the header? Or just the name? I think it should follow
								// the path as well, otherwise it is crazy. This should always be included.
								// ifndef is just a normal if for the header file!
								// Hey dick, __HEADER_H_INCLUDED__ is just a constant here, whose value is 1 I guess.
#define __MYCLASS_H_INCLUDED__

//==========================================================================
// When defining a class in a header, we my use other classes. The thing that we have to pay attention to
// is how we should include the corresponding headers where the original classes are defined.
// There are two methods here:
// Forward inclusion: Where we only add the class name, and not include the actual header where it is defined!
// Inclusion: Where we actually add the dependency as a header.

//==========================================================================
// Forward inclusion.
// It happens Under two circumstances:
//	1- When we have a reference/ pointer to said class.
//	2- one or more functions has a the object/pointer/reference as a parementer, or as a return type.
//  3- Friend classes are also forward defined. // I swear on never using firend classes.
// You should always forward declare what you can -- don't #include unless it's necessary. Unnecessary #includes can lead to trouble
class Forward;

//==========================================================================
// (Direct) inclusion.
// It happens under two circumstances:
//	1- When it is the parent class.
//  2- When use an instance of that class.
#include "Parent.h"
#include "Instance.h"
#include "../Classes/Inheritance.h"	// This is how we should referece the outside folders.
#include <vector>

// Declaration of the class
class Child : public Parent {
public:
	std::vector<int> vec;
	Instance instance;
	Forward* forward;
	void print(Forward* forward);
		
};

struct SimpleStruct {
	int x;
	const char* ptr;
};
#endif // !__HEADER_H_INCLUDED__


