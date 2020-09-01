/**
 * We have the following set of chars:
 * 
 * char: is the (usually) 8 bit entity. Guaranteed to have at least 8 bits. It's used for supporting ASCII (is it usaully signed?)
 * char maybe signed or unsigned.
 * signed char: a signed version of char.
 * unsigned char: an unsigned version.
 * 
 * wchar_t: A character set that is usually large enough to hold the entire char set of the locale. It
 * is large enough to hold UNICODE.
 * 
 * char16_t: A 16 bit char type, used for holding UTF-16
 * char32_t: A 16 bit char type, used for holding UTF-32
 * 
 * When it comes to chars, it's not safe to assume that chars are contiguous.
 * 
 * We may say char c = 'b'; int i {c}; The question however is that whether c is signed or unsigned, is it
 * implemented with one's complement or two's complement (hence, range from -127 to 127 or -128 to 127).
 * So even cast is not trivial.
 * 
 * Note that case from int to char is also possible, because chars are still integer types.
 * void digits(){for (int i=0; i!=10; ++i)cout << static_cast<char>('0'+i);
 * The character literal '0' is converted to its integervalue andiis added.  
 * The resultingintis then converted to acharand written tocout.  
 * Plain '0'+i is an int, so if I had left out thestatic_cast<char>, the output would have been something like 
 * 48,49,and so on, rather than 0,1, and so on.
 * 
 * 
 * The inital value of char is of course implementation dependent.
 * 
 * As we said the following cast is undefined:
 * char c = 255;
 * int i = c;
 * 
 * Because we don't know whether c (which is all one) is actually -1 or 255.
 * 
 * Character literals, confined to '', are of course in char.
 * 
 * We may also have char v1[] = "a", which contains as we know to chars, 'a' and '\0'.
 */

/**
 * Note that pointer conversion between signed and unsigned types is also not defined.*/
void f(char c, unsigned char uc, signed char sc){
    // char* pc = &uc; Error, no conversion
    // unsigned char* puc = &c; Error, no conversion

    // This behavior is also undefined sc = c;  Depends on the implementation.
}

/** Consider this in an 8bit system*/
void signedToUnsigned(){
    signed char sc = -160;
    unsigned char uc = sc;
    uc == 116; // (because 256-160==116). 160 + 116 = 256.
    
    char count[256]; 
    ++count[sc];  //likely disaster: out-of-range access
    ++count[uc];                     //OK
}