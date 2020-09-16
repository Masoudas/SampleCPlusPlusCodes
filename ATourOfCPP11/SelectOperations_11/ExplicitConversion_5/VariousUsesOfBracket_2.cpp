/**
 * The constructor notation T{} is used to express the default value of T. For the value
 * types, it will be the default value. Hence int{} is zero. For enumeration types, the default
 * value is ZERO!!!!See _8_4_1.
 * 
 * If a class has constructor that requires no parameters (either because it takes no 
 * parameters or because they're optional), the bracket notion uses that constructor to 
 * construct the class.
 * 
 * Explicitly constructed unnamed objects are temporary objects, 
 * and (unless bound to a reference) their  lifetime  is  limited  to  the  full  expression  in  which  they are  used  
 * In  this,  they differ from unnamed objects created using new (which need to be deleted, but can't, because there's
 * no reference to them.)
 */
class Date{
public:
    Date(){}
    Date(int n){}


};

enum A{a=1};

void f(Date& date){}

void g(){
    f(Date{});   // Default constructor of A, one with no parameter.
    f({});   // Default constructor of A, one with no parameter.

    Date d = Date{};    // One again, default date. What if there's no default value?

    Date d{};   // This I'm hoping mean default constructor!!!

    int a{};     // Default integer value.
    int b = int{};  // Default integer value.

    A a{};  // Default constructor of A, one with no parameter
    A a = A{};  // Again, the  default value.

}