/**
 * basic_string offers a variety of constructors. The most widely ones are:
 * 
 * basic_string s{};  // Empty construction.
 * string s1{"From C-Style String"};
 * string s2{s1};   // Copy constructor.
 * 
 * Don't initialize a string with a nullptr.
 */


/**
 * Other versions are:
 * 
 * - basic_string s {x,a}; s gets the characters from x; use allocator a.
 * - basic_string s {s2,pos,n,a}; s gets the characters s2[pos:pos+n); use allocator a. There's also a version without allocator.
 * - basic_string s {n,c,a}; s holds n copies of the character c; use allocator a
 * - basic_string s {b,e,a}; s gets the characters from [b:e); use allocator a. (Was is das?)
 */
#include <string>
#include <iostream>

using namespace std;
int main(){
    string str{'a', 'c', 'e'};
    cout << str << endl;    

    string str1{7, 'a'};    // Bjarne says this should return 7'a's, but in my machine, it returns two chars!
    cout << str1 << endl;    

    string str1{7, 5};    // Equivalent chars of 7 and 5.
    cout << str1 << endl;    
}
