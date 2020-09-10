/**
 * We know that every class by default has a copy constructor. What it does is that it essentially
 * copies the memory location of this object somewhere else. Hence, it is a shallow copy.
 * The copy constructor is essentially like this:
 * Class(const Class& other){
 *  memcpy(this, other, sizeof(Class));
 * }
 * Suppose we want to write an String mimicing class of our own. We'd have something like this
 */
#include <string>
#include <iostream>

class String
{
private:
    char* m_buffer;
    unsigned int m_size;
public:
    String(char* string){
        m_size = std::strlen(p);
        m_buffer = new char[m_size];

        /**
         * Note that memcopy takes the size in byte. Moreover, strlen returns the size of the string
         * not including \0. We add it here, which is important, specially for example when we stream
         * the string, so that it would know when to stop when streaming (otherwise we get a bunch of
         * weird chars until we face a null somewhere in the memory).
         */ 
        memcpy(m_buffer, string, m_size + 1); 
        m_buffer[m_size] = '\0';  // Because pointer may not end in null character.
    };

    /**
     * The destructor deletes the memory associated with the buffer.
     * 
     * As we see below, a combination of this destructor and the default copy
     * constructor causes a problem, which we will see below.
     */
    ~String(){
        delete[] m_buffer;
    };

    /** Making this class a firend of the operator defined below!!!*/
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

/** To make sure that we can print the string using an stream, we define the stream << operator here.
 * Then we make the String class a friend of this operator, that way, it can access it.
 * So now if we have an stream, we can say stream = stream << string. Like in a normal
 * cout we have cout << "something" << ... */
std::ostream& operator<<(std::ostream& stream, const String& string){
    stream << string.m_buffer;
    return stream;
}


void f(){
    String first = "Hey";

    /** As we know, here the copy constructor is called. Why not the '=' operator?
    String second = first;
}

