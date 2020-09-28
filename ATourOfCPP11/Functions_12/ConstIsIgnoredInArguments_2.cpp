/**
 * When declaring a function, due to compatibility with C, const is ignnored in function defintion.
 * Hence, these two are the same, and we get all sorts of errors, telling us that the function has already
 * been declared.
 */

#include <iostream>
using namespace std;

void f(const int x){
    std::cout << "Inside const function.";
}

void f(int x){
    std::cout << "Inside non-const.";
}

int main(){
    const int x = 1;
    f(1);
    f(x);
}