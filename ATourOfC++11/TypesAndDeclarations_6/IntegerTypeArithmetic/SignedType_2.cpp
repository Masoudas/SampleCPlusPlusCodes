/**
* If a signed number overflows or underflows, the result is undefined. Why?
*/
#include <iostream>
int main(){
    signed char c = -256;
    c--;

    std::cout << (int)c; // This didn't become 255! at least on this machine.
}