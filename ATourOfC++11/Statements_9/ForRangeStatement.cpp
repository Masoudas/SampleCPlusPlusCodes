/**
 * for (auto x : v);
 * The expression after the colon in for range must be a range. Hence, it must have a 
 * v.begin(), v.end() to obtain an iterator.
 * 
 * The compiler first looks for begin and end. If it sees that they're not a function (
 * for example are just variables), it throws an error. If this is not the case, the compiler
 * looks for begin and end in that scope, and if does not find one (for example because
 * because begin does not take an argument of its type), it returns an error.
 * 
 * The compiler uses v and v + N for a built in array of T v[N]. 
 * 
 * The <iterator> header provides begin(c) and end(c) for built-in arrays and for all 
 * standard-library containers.
 * 
 * As always, don't forget that elements are copied in the for loop (at least for the first one.
 * The second one? I guess v is initialized, hence just an assignment). Hence, it might be better
 * to use references here.
 * 
 * This is very elegeant when asking for variables from a user for example:
 * for (string s; cin>>s;)
 *        v.push_back(s);
 * 
 * 
 */
#include <string>
#include <iostream>

using namespace std;
int main(){
    string s1 = "Ex";
    string s2 = "Ey";


    cout << s1.compare(s2);
}