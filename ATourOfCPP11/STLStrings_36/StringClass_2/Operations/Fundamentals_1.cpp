/**
 * As we already know, == is not defined by default for a class. Let's not forget than.
 * 
 * For basic_string, we have the following comparison:
 * 
 * a == b:  The strings are equal lexicographically (note that it's not like Java where strings are immutable).
 * a != b; not of previous !(a==b)
 * s<s2 Is s lexicographically before s2?
 * s<=s2 Is s lexicographically before or equal to s2?
 * s>s2 Is s lexicographically after s2?
 * s>=s2 Is s lexicographically after or equal to s2?
 */
