/**
 * Because std::string is in fact a pointer to char, it's allocated on the heap.
 * Hence, we can return one from a function, and there's no need to use new
 */

#include <string>
#include <iostream>
#include <vector>

/**
 * Note that string is returned, even though we did not use new. It's apparantly allocated on the heap. We don't need
 * to manage it, or delete it. Same goes for example for vector for example. So no need to use new with these expressions.
 */
std::string reverse_string(const std::string& s ){
    std::string ss;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        ss.push_back(s[i]);
    }
    
    return ss;
}

/** apparently vector is allocated on the heap, because it's elements are stored on the heap! 
*/

std::vector<int> vecIsTheSame(){
    return std::vector<int>{1,2,3};
}

int main(){
    const std::string str = "AX";

    std::cout << reverse_string(str) << std::endl;

    std::vector<int> vec = vecIsNotTheSame();

    std::cout << vec[0];
    std::cout << vec[2];
}