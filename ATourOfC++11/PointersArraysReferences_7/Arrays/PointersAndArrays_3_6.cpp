/**
 * First off, note that array pointer is a constant pointer, hence an expression like arr++ is 
 * incorrect (naturally of course).
 * 
 * We have the basic assignments:
 * int v[] = {1, 2, 3, 4};
 * int* p = v;
 * int* p1 = &v[0];
 * int* p2 = v + 2;
 * 
 * What's the difference between &v and v in the following expression?
 * int (*p3)[3] = &v;
 * int* p4 = v;
 * 
 * Well as we know, the last one does an implicit conversion to pointer. The first however,
 * explicitly extracts the address to a pointer to array.
 * 
 * */

/**
 * We have the following equivalencies to access the Jth element of array v:
 * a[J] = *(a+J) = *(J + a) = *(&a[0] + J);
 */ 

/**
 * How do we pass reference to an array of N integers?
 * int (&p5)[4] = v;
 * int (*p6)[4] = v;
 * Note that with this reference, p6++ moves forward 4 ints, not 1 int!
 */ 

/**
 * The following two formats for looping over an array are both correct, and
 * do the same thing (don't forget that this is possible because we have a char
 * array, otherwise, we needed the size).
 */ 
void l1(char c[]){
    for (int i = 0; c[i] != '\0'; i++)
    {
        // use c[i]
    }

    for (char* p = c; *c != '\0'; p++)
    {
        // use p
    }
    
    
}

/**
 * There's an implicit conversion from array to pointer (hence, they're not the same).
 * For example:
 */ 
extern "C" int strlen(const char*); // import from <string.h> in C
void f(){
    char v[] = "AnnMarie";
    char* p = v;    // This is ok.

    strlen(v);  // Returns the length of v, not including \0;
    strlen(p);  // Same as above;

    // v = p;  // Assignment from pointer to array is impossible. (Even though v is an lvalue.)
}
/**
 * As the above example shows, when passing an array to a pointer argument,  an implicit conversion
 * to pointer occurs. Hence, the array size is lost.
 * 
 * Note that as we said, there's no copy assignment when it comes to arrays. Hence, when we
 * pass an array, it's not copied (just their pointers!). Hence an array passed to a function
 * is modified by the function.
 * 
 * The above is the most important reason why we should use std::array, std::vector or std::string,
 * because they pass on their size as well.
 */ 


/**
 * As a point of interest we know that pointers may be integers in an of themselves. So for *T,
 * the size of (p+1) - p would be equal to sizeof(T). */

/**
 * As another point of interest, two pointers can be subtracted from one another, only when they refer to the
 * same array. So if p - q, the result would be the number of elements in the [p:q) array. 
 * For example: */
void f(){
    int v1[10];
    int v2[10];

    int i1 = &v1[5] - &v1[3]; // This would be v1[4], v1[5], hence 2;
    int i2 = &v1[5] - &v2[3]; // Result undefined.

    int i3 = &v1[3] - &v1[5]; // I think this would return -2.
}

/**
 * Another point is that the range "for" loop only works for arrays of known size. Hence, the
 * following example don't compile:*/
void f(char v[]){
    // for (auto c : v){} This will not work
    
}

/** ---------------------------------------------------------------------- **
 * Going back to arrays and pointers, we now know that:
 * int a[] = {1,2};
 * 
 * int *b = a;
 * 
 * This is because a is a 1D array of pointers to integers. Now what is &a[0]? It's the address
 * of first integer, hence again int *b = &a[0]. 
 * 
 * Now what is &a? It's the address of a pointer to a 1D array of 2 pointers. Hence, 
 * int (*c)[5] = a;
 * 
 * Now consider int a[2][3]; 
 * 
 * What is a? It's a 1D array of pointers to arrays of 3 ints. 
 * 
 * What is a[0]? It's value is a 1D array of pointer to int (or a 1D array). hence int *x = a;
 * What is &a? It's the address to an array of 1D pointers to array of 3 ints. Hence int (*a)[2][3] = &a;
 * What is &a[0]? It's the address to an array of 3 ints. Hence, int (*x)[3] = a;
 * 
 */

 
