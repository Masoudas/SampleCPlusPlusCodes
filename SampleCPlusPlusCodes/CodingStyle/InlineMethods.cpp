// See https://www.geeksforgeeks.org/inline-functions-cpp/.
// The idea is that sometimes the time needed to call a function from memory, and put in CPU and put the variables in slack
// could take a long time for a method. In this case, we use inline methods. What inline does is that it will directly
// put the copy of the function inside where ever the function is called. The compiler decides on whether to put the function or 
// actually call it upon execution. Usually, small functions are called inline.

using namespace std;

inline int cube(int s)
{
	return s * s * s;
}

int InlineMethods()
{
	cout << "The cube of 3 is: " << cube(3) << "\n";
	return 0;
} //Output: The cube of 3 is: 27 


// Class methods are implicitly inline! Makes sense I suppose. Because when you call it somewhere, maybe it's best for the compiler to inline it.
// Usually when we want to explicitly say a class method is inline, we declare it outside the class.


class S
{
public:
	int square(int s); // declare the function 
};

inline int S::square(int s) // use inline prefix 
{
	return s * s;
}
