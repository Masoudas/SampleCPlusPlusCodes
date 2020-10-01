/**
 * list is a doubly linked list in c++. A single linked list is a forward_list
 */

#include <list>
#include <iostream>

using namespace std;
int main(){
    list<int> ls{1, 2, 3};

    list<int>::iterator begin = ls.begin();
    list<int>::iterator end = ls.end();

    for (; begin != end; ++begin)
    {
        cout << *begin << endl;
    }


    // _List_iterator<list<int>> begin_a = ls.begin(); Why wouldn't these work?
    // _List_iterator<list<int>> end_a = ls.begin();
}

