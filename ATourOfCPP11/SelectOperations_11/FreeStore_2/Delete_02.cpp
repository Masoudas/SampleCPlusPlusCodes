/**
 * An object created by new is in the memory until it's deleted, using the delete keyword.
 * The delete keyboard ONLY accepts a pointer.
 * 
 * delete can be applied to nullptr with no problem (phew!!). However, when applied to memory
 * that's already been deleted, throws an exception (Question is, how does it know that the memory
 * does not belong to C++?)
 */
#include <iostream>

int main(){
    int* ptr = nullptr;
    delete ptr;

    int x{};

    //delete x; This statement is incorrect!

    int* p1 = new int{99};
    int* p2 = p1; // potential trouble
    delete p1; // now p2 doesn’t point to a valid object
    p1 = nullptr; // gives a false sense of safety
    char* p3 = new char{'x'}; // p3 may now point to the memory pointed to by p2
    //*p2 = 999; // this may cause trouble

    std::cout << *p2 << '\n'; // Does not print 99, because its location is not in use.
}

/**
 * We can summarize problems associated with memory in three bullet points:
 * 1- Leaked objects: One forgets to delete the objects.
 * 2- Premature delete: One deletes a pointer, however that memory is still being used.
 * 3- Double deletion: This one stops the operation of the code and throws an exception.
 */
void sloppy() // very bad code
{
int∗ p = new int[1000]; // acquire memory
// ... use *p ...
delete[] p; // release memory
// ... wait a while ...
delete[] p; // but sloppy() does not own *p
}

/**
 * To overcome this issue, 
 * 1- prefer scoped variables over heap variables as much as possible. Moreover,
 * 
 * 2- Use memory handler objects such as shared_ptr, unique_ptr, weak_ptr;
 * Also, using move semantics can take of this problem as well. Because if we're initializing a new 
 * reference, we want to just move the object, and steal the resources of the first one.
 * 
 * The latter is the RAII principle, better known as resource allocation is initialization.
 */ 