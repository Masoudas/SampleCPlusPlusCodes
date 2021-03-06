/**
 * auto and decltype() are used to deduce the type of an expression. 
 * 
 * auto: for deducing a type of an object from its initializer; 
 *  the type can be the type of a variable, a const,or a constexpr.
 * 
 * decltype(): for deducing the type of something that is not a simple initializer, 
 * such as the return type for a function or the type of a class member.
 */ 


/**
 * Take a look at this one.
 */
 #include <iostream>
 
struct A { double x; };
const A* a;
 
decltype(a->x) y;       // type of y is double (declared type)
decltype((a->x)) z = y; // type of z is const double& (lvalue expression)
 
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) // return type depends on template parameters
                                      // return type can be deduced since C++14
{
    return t+u;
}
 
int main() 
{
    int i = 33;
    decltype(i) j = i * 2;
 
    std::cout << "i = " << i << ", "
              << "j = " << j << '\n';
 
    // lambda expression can be named using auto.
    auto f = [](int a, int b) -> int 
    {
        return a * b;
    };
 
    decltype(f) g = f; // the type of a lambda function is unique and unnamed
    i = f(2, 2);
    j = g(3, 3);
 
    std::cout << "i = " << i << ", "
              << "j = " << j << '\n';
}

/**
 * The use of auto can help make less prone to change. For example with an iterator
 * if we changed the type of iterator, then the second for would be fine, whereas the
 * first one needs change in the future.
 */ 
template<typename T> f(std::vector<T>& vec){
    for (vector<T>::iterator p = vec.begin(); p != vec.end(); vec++)
    {
        *p = 7
    }

    for (auto p = vec.begin(); p != vec.end(); vec++)
    {
        *p = 7
    }
    
}

/** Use of auto can cause unexpected problems as well.*/
int f(double x){
    auto index = x + 7;
    int arr[2];

    return arr[index];  // Error
}

/** 
 * auto can be decorated with specifiers (like const) and modifiers (*, &) as well.
 */ 
void f(vector<int>& x){
    for (auto& y : x)   // Access by reference to int. Although this is totally unnecessary.
    {
    }
}

/** Note that the type of an expression is never a reference because references are implicitly deref-erenced in expressions.  
 * For example:*/
void g(int& v){
    auto x = v; //x is an int (not an int&). This was veryimportant.
    auto& y = v;//y is an int&
}

/* When using auto, however, we prefer '=', (Me: because of ambiguity between single list and int
* auto v {99}; Is it an int, or a list? It is actually a list, but we might think of it as int.)
*/
void init(){
    auto x1 = {1}; auto x1 {1}; // Both a list of int with one element.

    // auto x3 = {1, 1.1}; // Error, cannot deduce type.
}