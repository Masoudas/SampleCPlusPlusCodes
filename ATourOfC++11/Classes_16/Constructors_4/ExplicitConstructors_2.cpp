/**
 * A constructor is essentialy an implicit type converter, from the given type to the
 * class type. This is why when defining a class String such as:
 * Class String{
 *      String(char* str){...}
 * }
 * 
 * we can write:
 * String str = "a";    // Converts implicity "a" to String.
 * String str1 = {"a"}; // Another implicit conversion format. This is not a list.
 * 
 * Implicit constructors can get messy. For example
 * void f(String s) {
 * }
 * 
 * then we can say:
 * void g(){
 *      String s;
 *      f("2"); // Calling the implicit constructor!!!!
 * 
 *      s = "a"; // What is this? Is it assignment, or reinitialization? It is reinitialization, but obscure.
 *      
 * }
 * 
 * In some rare cases, this can be a good idea. For example with the Complex number class,
 * where we may want this so that we can define a complex number on the real axis as:
 * Complex<double> e = 1;   // Initiate to 1 + 0j.
 * 
 * To avoid using a constructor as implicit type converter, we can use the 'explicit' keyword to
 * indicate that it's an explicit one. Explicit is mostly important for single parameter constructors.
 * Howeve a default constructor with two integers say like this can also be vague
 * 
 * Class a = {1, 2};    // Calling the implicit constructor!
 */

class Date {
    int d, m, y;
public:
    explicit Date(int dd =0, int mm =0, int yy =0);//...
};
    
Date d1 {15};//OK: considered explicit
Date d2 = Date{15}; //OK: explicit. Funny enough, here the copy constructor is called!
Date d3 = {15};//error : = initialization does not do implicit conversions
Date d4 = 15;//error : = initialization does not do implicit conversions

void my_fct(Date d){

}

void f(){
    my_fct(15);               //error : argument passing does not do implicit conversions
    my_fct({15});             //error : argument passing does not do implicit conversions
    my_fct(Date{15});     //OK: explicit//...
}


/** If a constructor is declared explicit and defined outside the class, 
 * explicit cannot be repeated:*/
class Date {
    int d, m, y;
public:
    explicit Date(int dd);//...
};

Date::Date(int dd) { /*...*/ }//OK  
explicit Date::Date(int dd) { /*...*/ }//error