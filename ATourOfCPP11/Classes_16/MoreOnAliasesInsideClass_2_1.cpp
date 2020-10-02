/**
 * So when aliasing, sometimes we have a situation like this, where UsingAliases
 * is defined before the classes it aliases. This happens for example when we try to define iterator
 * of a class on top of the class it iterates. In such situations, because the compiler still has 
 * no access to what's happening, we need to define it for him. Say for example B is a class (class B),
 * it has a scope template (hence typename B::Type) and so forth. 
 * 
 * Note that if we didn't define using Templated_Other = class B;    // We must use class,
 * then we wouldn't be able to say:
 * 
   using Templated_Other_Template = typename B::Type;  // We must use typename
 * 
 * which is odd. Also, pay attenention to the fact that once we said class B, we didn't need to define
 * B again, because B and it's alias can be used interchangeably (Templated_Other == class B, so it
 * doesn't matter which one you use)! However, we could have said:
 * 
 * using Templated_Other_Template = typename Templated_Other::Type;  // We must use typename
 * 
 */
template <typename T>
class UsingAliases{
    using Template = T; // This is fine, we don't use typeName
    using Template_WithTypeName = typename T; // This is fine, we can use typeName
    using Other = class A;    // We must use class. We can't use typename
    
    using _INT = int;   // Again, fine

    using Templated_Other = class B;    // We must use class
    using Templated_Other_Template = typename B::Type;  // We must use typename
    using Templated_Other_Template_1 = typename Templated_Other::Type;  // We must use typename

    using Templated_With_class_Declare = class C;    // We must use class
    using Templated_With_class = class C::Type;
    Other o{};

};

class A{

};

template <typename T>
class B{
public:
    using Type = T;

};

template <class T>
class C{
public:
    using Type = T;

};

template<typename C>
class D{

};

template <typename T>
class UsingAliases_1{
    using Template = T; // This is fine, we don't use typeName
    using Template_WithTypeName = T; // This is fine, we can use typeName
    using Other = A;    // We must use class. We can't use typename
    
    using _INT = int;   // Again, fine

    using Templated_Other = B;    // We must use class
    using Templated_Other_Template = B::Type;  // We must use typename

    using Templated_With_class = C::Type;
    Other o{};

};