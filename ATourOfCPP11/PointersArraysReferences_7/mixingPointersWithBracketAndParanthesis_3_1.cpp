/**
 * There were a couple of rules. 
 * 1- Go right when you must.
 * 2- Brackets and paranthesis have precedence over pointers and references.
 * 
 * int* a[5]; a is (precedence, go right) an array of 5 pointers to int.
 * 
 * int a*[5]; a is a pointer to array of five integers.
 * 
 * We must always remember that out-of-range access is never checked. Hence, it results in 
 * UNDEFINED BEHAVIOR.
 * 
 * 
 * Array size must be an expression (of course, because with arrays, we need to assign a
 * specific size in memory). For variable expressions, we need to use vectors.
 */ 

void f(int n){
    int v1[n];//error : array size not a constant expression
    vector<int> v2(n);//OK: vector with n int elements
}

/** An array can be allocated statically, on the stack, and on the free store.  For example:*/
int a1[10];//10 ints in static storage
void f(){
    int a2 [20];  //20 ints on the stack
    int∗ p = new int[40]; //40 ints on the free store//...
}

/**
 * Bjarne says arrays should not be passed as function parameters, because that is the source of
 * many problems. This is because an array is converted to its pointer when being passed.
 * 
 * Arrays usually should not be used directly, but rather be capsualted.
 * 
 * Arrays allocated on the free store should be deleted, only once, and only
 * when they go out of scope. That’s most  easily  andmost  reliably  done  by  having  the  lifetime  
 * of  the  free-store  array  controlled  by  a  resource  handle
 * (e.g.,string(§19.3, §36.3), vector(§13.6, §34.2), orunique_ptr(§34.3.1)). 
 * automatic arrays should not be deleted. 
 */