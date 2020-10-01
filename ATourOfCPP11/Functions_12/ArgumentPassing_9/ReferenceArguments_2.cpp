/**
 * As we know f(int& x) changes the value of x. Hence, passing by reference should be done
 * with cautious (I'd say). Pefer passing as constant ref!
 * 
 * We should try and do the same with pointers as well.
 * 
 * The absence of const in the declaration of a reference argument is taken as a statement of intent to modify the variable.
 * 
 * void g(Large& arg); // assume that g() modifies arg
 * 
 * The same situation happens with pointers: 
 * int strlen(const char∗); //number of characters in a C-style string
 * char∗ strcpy(char∗ to, const char∗ from); // copy a C-style string
 * int strcmp(const char∗, const char∗); //compare C-style strings
 */

