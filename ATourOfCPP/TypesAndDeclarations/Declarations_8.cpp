/**
 * Declaration grammar is very complicated. Here's the five essential parts:
 * 
 * 1- Optional prefix specifiers (like static, virtual).
 * 2- A base type (e.g, vector<double> or const int).
 * 3- A declarator optionally including a name (e.g, p[7], *(*)[]).
 * 4- Optional suffix function specifiers (e.g, constexr, noexception).
 * 5- An optional initializer or function  body (e.g, {1,2} or {return -1}).
 * 
 * For example, consider const char∗ kings[] = { "Antigonus", "Seleucus", "Ptolemy" };
 * unsigned ui;   //OK: ‘‘unsigned’’means ‘‘unsigned int’’
 * long li;       //OK: ‘‘long’’ means ‘‘long int’’
 * 
 * It is possible to declare several names together.
 * int x,y; // int x; int y;
 * 
 * Operators only apply to the closest definition.
 * int* x, y; // int *x, int y;
 * int *x, y; // int *x, int y;
 * 
 * 
 * As for variable declarations, a name in a scope hides the name in an outer scope. Hence it's best avoided
 */
void f(int x){
    {
        int x = 10; // Hides the outer x.
    }
}


/**
 * A name in a global scope can be accessed via the scope ::.
 * int x = 10;
 * ::x = 10;
 */

/** The scope of a name that is not a class member starts at its point of declaration, that is,
 *  after thecomplete declarator and before the initializer.  
 *  This implies that a name can be used even to specifyits own initial value.  
 *  For example:*/
 int x = 97;
 void f3(){
     int x = x;//perverse: initialize x with its own (uninitialized) value. This is x = 97.
}

/**
 * Don't forget that a function is a scope. Hence, this declaration is wrong
 * */
void f4(int x){
    // int x = 5; This is wrong, because x is already defined in this scope.
}