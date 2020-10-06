/**
 * As another point, note that when passing template to class, writing a class name that already exists DOES NOT
 * imply that we're using that class as template. It's just a name for a template. However,
 * this is fortunate, because like we discussed in _2_1, if that class is to be defined after,
 * we don't have to redefine it in the class. It's already defined as a typename.
 * 
 */

template <typename A>   // We can't say <typename A<T>>, no such thing
class TemplatePassing{
    using Type = typename A::T; // Ready _2_1 to understand why we need a typename keyword here.
};

template <typename T>
class A{
public:
    using Type = T;
};

int main(){
    
}