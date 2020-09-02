/**
 * Integers come in three flavours, int, unsigned int and signed int.
 * They also come in four forms, short int, int, long int, long long int.
 * 
 * short is guaranteed at least 16 bits, long at least 32 bits.
 * 
 * Default value is a suitable representation of zero for all types.
 *  
 * Note that short is a synonym for short int.
 * unsigned is sysnonym fir unsigned int, and singed for signed int.
 * 
 * Using an unsigned instead  of  an int to  gain  one  more  bit  to  represent  positive
 * integers  is  almost  never a good  idea. Attempts  to  ensure  that  some  values  are  
 * positive  by declaring  variables unsigned will  typically  be defeated by the implicit conversion rules.
 * 
 * Unlike plainchars, plainints are always signed.  The signed int 
 * types are simply more explicit synonyms for their plain int counterparts, rather than different types.
 * 
 * the <cstdint> provide us with some type definition.
 * int64_t is a signed 64 bit. uint_fast16_t is an unsigned int with exactly 8 bits, supposedly the fastest
 * of such type, and so forth.
 * 
 * The literals come in three forms, decimal, octal and hexadecimal. Decimals are like 123123211.
 * Hexadecimals are like 0x43, and octals are like \x127.
 * 
 * U can be used to explicitly indicate unsigned, L is for longs. Combinations are allowed.
 * We also have LL.
 * long l = 123UL;
 * 
 * If no suffix is provided, the compiler gives an integer literal a suitable type based on
 * its value and the implementation’s integer sizes.
 * 
 * Literals have the following assignment rules:
 * 1- If a decimal has no suffic, then it's interpreted as int, long int, long long int.
 * 2- If it is octal or hexadecimal and has no suffix, it has the first of these types 
 *   in which its value can be represented: int, unsigned int, long int, unsigned long int,
 *   long long int, unsigned long long int.
 * 3- If it has u suffix, then unsigned int, unsigned long int or unsigned long long int.
 * the rules don't stop here!
 */