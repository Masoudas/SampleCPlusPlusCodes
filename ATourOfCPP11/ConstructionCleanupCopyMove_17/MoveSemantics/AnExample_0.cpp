/**
 * How can the compiler distinguish when to use move constructor and when to use 
 * copy constructor? Well the answer is, when we have an Rvalue reference, it used
 * the move constructor. Question is, when do we have an rvalue reference normally?
 * Well, one common case is when create we a new object, we actually have an rvalue.
 * class1{new class()}. The class on the inside would be an rvalue, hence if class1 
 * has a copy constructor, that will be used.
 * 
 * We can check this below using a Person class that uses a String class.*/

class String
{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String() = default;

    String(char* string){
        m_size = std::strlen(string);
        m_buffer = new char[m_size + 1]; 
        std::memcpy(m_buffer, string, m_size + 1); 
        m_buffer[m_size] = '\0';
    };

    String(const String& other) {
        m_size = other.m_size;
        m_buffer = new char[m_size + 1];    
        memcpy(m_buffer, other.m_buffer, m_size + 1);   // Copies the initial object to a new memory location
    }

    ~String(){
        delete[] m_buffer;
    };
};

class Person
{
private:
    String person;  // When we define this, person is null (most likely, hence, it's not initialized yet).
public:
    Person(const String& p){
        person = p;    // Here, the copy constructor is called. Why? Because person has not been initialized yet!
                        // As we know, class members are not initialized by default (see Chapter _16, Constructors_4, _0)
    };
    ~Person();
};

