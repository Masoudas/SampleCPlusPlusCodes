#include <exception>

template<typename T>
struct Node{
    T item;
    Node<T>* next;

    Node(T item) : item(item), next(nullptr){}
};

template<typename T>
class Queue{
private:
    int N;
    Node<T>* first;
    Node<T>* last;

public:
    Queue() : N(0), first(nullptr), last(nullptr){}
    void enqueue(T t);
    T dequeue();
    int size(){return N;}
    bool isEmpty(){return N == 0;}

    ~Queue(){
        // We need to remove every item from the heap.
    }
};

template<typename T>
void Queue<T>::enqueue(T t){
    Node<T>* oldLast = last;
    last = new Node<T>{t};

    if (oldLast != null){
        oldLast->next = last;
    } else{
        first = last;
    }
    ++N;
}

template<typename T>
T Queue<T>::dequeue(){
    if (isEmpty()){
        throw run_time("Stack is empty");
    }
    
    Node<T>* oldFirst = first;

    T item = first->item;
    first = oldFirst->next;

    delete first;

    --N;
    return item;
}

template<typename T>
void ~Queue<T>(){
    if (isEmpty()){
        return;
    }

    for (Node<T> node = first; node != null;)
    {
        Node<T> oldNode = node;
        node = oldNode->next;

        delete oldNodel

    }
    
}