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
 * Why? Because l is a reference to an lvalue as we said, but 1 isn't an lvalue!
 * However, with constants, c++ allow us this type of initialization:
 * const double &l {1};
 * It takes the value and makes an implicit  conversion to the type, then puts it in a
 * temporay location of memory, and then puts the address of that memory in l.
 * 
 * Question is, why do we need reference to constants? Note that the reference by itself is constant,
 * hence the constant part always refers to the value. So the value is constant.
 * 
 * As we know by now, the following function changes the value of the reference. It is
 * however better not to write programs that change their arguments, but rather return
 * a new value (really? How about when I want to add a shift to an image for example.)
 * The point is that we need to strongly indicate that the arguments are changing.
 */
void f(int& r){
    r++;    // Changes the value of r on the outside.
}

/**
 * Now, because and a reference is an lvalue, if returned by a function can be assigned to. This
 * may at first seem bizzare, but for example if we override the [] operator, we want to be able
 * to assign to the result. Hence, it's usually a good idea to return &T, as does the
 * operator[] function of the Map class of STL. An implementation is given below.
 * 
 * Now for example, the user might say ++map[t], because map returns an lvalue, and it is now modified.
 */
template<class K, class V>class Map {//a simple map class
public:
    V& operator[](const K& v);//return the value corresponding to the key v
    pair<K,V>∗begin() { return &elem[0]; }
    pair<K,V>∗end() { return &elem[0]+elem.size(); }
private:
    vector<pair<K,V>> elem;//{key,value} pairs
};

/** It pass  the  key  argument,k, by reference  because  it  might  be  of  a  type  that  is  expensive  to copy.
 * Similarly, It return the value by reference because it too might be of a type that is expensive to copy.*/
template<class K, class V>V& Map<K,V>::operator[](const K& k){
    for (auto& x : elem)
        if (k == x.first)
            return x.second;
    
    elem.push_back({k,V{}});         //add pair at end 
    return elem.back().second; //return the (default) value of the new element
}

/**
 * Here's a cool use of this map. We want to count the number of appearance of each individual
 * substring in a string. */
int main(){
    Map<string, int> map;

    for (string s; cin >> s; ) ++map[s];    // Cool line of code. Apparently cin reads one word from the input stream and
                                            // puts it in s. the rest is clear. We add to key corresponding to stream.
    for (const auto* x : map){
        cout << x.first << ": " << x.second << '\n';
    }
    
}
