/**
 * An enumeration is a type that can hold a set of integers. Enumeration values are called
 * enumerators.
 * 
 * A basic difference between enum class and a plain enum is that a plain enum can be implicitly
 * converted into an int, whereas as an enum class can't. It should be cast explicitly.
 * The other weird one is that a plain enum can be seen all throughout the scope!!!whereas an
 * enum class are local to the enums and variables.
 * 
 * The default value for an enum (i.e, with a bracket) is always ZERO! whether 0 is actually part
 * of the enum or not.
 * 
 * The default value of each enum is zero. (Me: Don't use enums for their integer values!)
 * 
 * In general, prefer enum classes!!!
 */
#include <iostream>

using namespace std;
enum class A{a=1,b};
enum B{c=2, d}

int main()
{
    A x = A{};
        
    cout << static_cast<int>x; // prints one.

    cout << static_cast<int>a; // This of course does not make sense!
    cout << d; // This however prints 3, because the the enum values are accessible throughout the scope.

    return 0;
}