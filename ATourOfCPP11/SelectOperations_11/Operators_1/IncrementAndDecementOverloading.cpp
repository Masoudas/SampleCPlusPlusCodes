/**
 * As we know, ++x takes no ints (per se), whereas x++ is x = x + 1;
 * 
 * So in a class, we can overload prefix increment by writing operator++() and postfix increment by
 * writing operator++(int); The int inside is just for distinguishing the two operators.
 * 
 * In a non-member function, because we need to indicate with the pre and post increment are working on,
 * we ask for a reference to the type they'are working on. We ask for a reference because we want to change
 * the value of the underlying type. Naturally there's no return here.
 * See the examples below. 
 */
#include <iostream>
using namespace std;

class Increment{
public:    
    int x = 0;

    void operator++(){
        ++x;
    }

    void operator--(int w){
        --x;
    }
};

int main(){
    Increment c;

    ++c;
    cout << "This should print 1: " << c.x << endl;

    c--;
    cout << "This should print 0: " << c.x;
}