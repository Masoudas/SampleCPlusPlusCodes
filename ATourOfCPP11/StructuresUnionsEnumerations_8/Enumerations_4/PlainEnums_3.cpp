/**
 * We can have unnamed enums, mostly in a class. We now see why they're useful. They can
 * be accessed without the name inside the scope (see Basics_1). Hence, we can directly access
 * their values.
 */

/**
 * Also, take a look at this weird declaration of enum, where we define the enum outside the namescop,
 * hence, the need to use the scope operator.*/
namespace A{
    enum Class_Enum;
}

enum A::Class_Enum{Two};



