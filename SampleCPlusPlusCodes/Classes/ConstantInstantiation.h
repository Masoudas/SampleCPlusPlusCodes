#ifndef __CONSTANT_INSTANTIATION_H__
#define __CONSTANT_INSTANTIATION_H__

// When an object of a class is qualified as a const object. The access to its data members from outside the class is restricted to read-only, 
// as if all its data members were const for those accessing them from outside the class. Note though, 
// that the constructor is still called and is allowed to initialize and modify these data members:

// A non constant method cannot be called from inside a constant method while defining the class.

//Member functions can be overloaded on their constness : i.e., a class may have two member functions with identical signatures 
//except that one is constand the other is not: in this case, the const version is called only when the object is itself const, 
//and the non - const version is called when the object is itself non - const.

class ConsClass {
public:	 
	int value = 1;
	int sum(int val) const { return this->value + val; };
							// value += 1; This is not allowes either.
							//return this->performSum(this->value, val); 	};	// This is not allowed
						// The word constant must come after function definition to indicate 
						// that this is a constant member.  If we define the function as const int sum(int), 
						// it will assume that we are returning a constant integer, which is different from what we seek.
	int sum(int val) { return this->performSum(this->value, val); };	// This is not allowed
	int performSum(int x, int y) { return x + y; };	// This method cannot be invoked when the class is instantiated constantly.
						
};

#endif // !__CONSTANT_INSTANTIATION_H__

