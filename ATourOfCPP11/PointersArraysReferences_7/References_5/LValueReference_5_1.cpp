/**
 * lvalue references must always be initialized.
 * 
 * Because the value of a reference can't be changed, there are no operators working on reference.
 * We can think of a reference as a constant pointer to the object, which is not separate from the
 * object itself.
 * 
 * Here's something interesting. This initialization is wrong. Why?
 * double &l = 1; // Wrong.
 * 
 * Why? Because l is a reference to an lvalue, which 1 isn't!
 * However, with constants, c++ allow us this type of initialization:
 * const double &l {1};
 */