/**
 * By declaring a function a constant expression, we say that we want to use it in constant expressions,
 * if given constant arguments. 
 */
constexpr int fac(int n)
{
    return (n>1) ? n * fac(n-1) : 1;
}
constexpr int f9 = fac(9); // must be evaluated at compile time

/** When used in an object definition, it means evaluate the initializer at compile time.’’ For example: */
void f(int n)
{
    int f5 = fac(5); // may be evaluated at compile time
    int fn = fac(n); // evaluated at run time (n is a var iable)
    constexpr int f6 = fac(6); // must be evaluated at compile time
    constexpr int fnn = fac(n); // error : can’t guarantee compile-time evaluation (n is variable)
    char a[fac(4)]; // OK: array bounds must be constants and fac() is constexpr
    char a2[fac(n)]; // error : array bounds must be constants and n is a var iable
    // ...
}

/**
 * constexpr can't have for loops or if expressions (Ternary ifs are ok apparently). Recursion is also allowed.
 * It must not have sideeffects as well (like changing a global variable).
 * We must not use with long methods, because compile time would be long.
 */
int glob;
constexpr void bad1(int a) // error : constexpr function cannot be void
{
glob = a; // error : side effect in constexpr function
}

/**
 * We may use constexpr with constructors! That way, the object is created in ROM!
 * A constant expression constructor has no body, and is only allowed to initialize data.
 * 
 * Like a constexpr function, however, if the values that are used are not constant, the 
 * initilization would be dynamic
 */
struct complex
{
    //a constant expression constructor
    constexpr complex(double r, double i) : re(r), im(i) { }//empty body
    
    //constant expression functions
    constexpr double real() { return re;}
    constexpr double imag() { return im;}

private:
    double re;
    double im;
};

constexpr complex COMP(0.0, 1.0); // creates a literal complex

void f(){
    double val = 0.2;
    complex(val, val);  // This initialization is not constant expression

    double x = 1.0;
    
    constexpr complex cx1(x, 0); // error: x isn’t a constant expression
    
    const complex cx2(x, 1); //OK, dynamic initialization
    constexpr double xx = COMP.real(); // OK
    constexpr double imaglval = COMP.imag(); //OK, static init
    complex cx3(2, 4.6); //dynamic initialization
}