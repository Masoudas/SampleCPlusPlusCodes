#include <iostream>
using namespace std;

struct node {
	int x;
	node* back;	// Here, as we move forward with the list, we make sure to refer back to previous elemen of the list.
};

void push(node*& linkedList, int x) {
	node* newNode = new node{ x , linkedList };
	linkedList = newNode;

	// Why is it wrong like this?
	//node newNode;
	//newNode.x = x;
	//newNode.back = linkedList;
	//linkedList = &newNode;

}

void print(node* linkedList) {
	while (linkedList != nullptr) {
		cout << linkedList->x << "\n";
		linkedList = linkedList->back;
	}

}

void LinkLists(void) {
	// As is clear from the name, we can create a linked list using strucutres.
	node* linkedList = nullptr; // The first pointer should be zero, so that we know where we are.

	push(linkedList, 1);
	push(linkedList, 2);
	push(linkedList, 3);

	print(linkedList);

}

#include <list>
#include <iostream>
using namespace std;
void LinkedListsFromLibrary(void) {
	list<int> myList, myList1;	// No random access is supported with list.
								// Unless the elements are popped, no matter how many times we iterate over the list, they will remain there.
	for (int i = 0; i < 10; i++) {
		myList.push_back(i);	// Adds elements to the back of the list
		myList.push_front(i + 1); // Adds elements to the front of the list.
		// The first element of this list would be 9
		// The first element of this list would be 10
	}

	cout << myList.empty() << endl;	// Whether list is empty.
	cout << "First List is" << endl;
	for (int element : myList) {	// iterating over an iterative element is simple! always iterated from the last item
		cout << element << endl;
	}

	myList1.assign(5, 500);	// Assigns element the, the first element being the number of repetition.
	cout << "Second List is" << endl;
	for (int element : myList1) {	// iterating over an iterative element is simple! always iterated from the last item
		cout << element << endl;
	}

	int arr[3] = { 1, 2, 3 };
	myList1.assign(arr, arr + 3);	// Assigns from a list. Notice that the last pointer is one larger than the actual number of pointers.
	cout << "Third List is" << endl;
	for (int element : myList1) {	// iterating over an iterative element is simple! always iterated from the last item
		cout << element << endl;
	}

	myList1.assign(myList.begin(), myList.end());	// Assigns from a list. Notice that the last pointer is one larger than the actual number of pointers.
	cout << "Fourth List is" << endl;
	for (int element : myList1) {	// iterating over an iterative element is simple! always iterated from the last item
		cout << element << endl;
	}

	int front = myList.front();
	myList1.assign(front, front + 3);	// Assigns partially from a list.
	cout << "Fifth List is" << endl;
	for (int element : myList1) {	// iterating over an iterative element is simple! always iterated from the last item
		cout << element << endl;
	}

	myList.pop_back();	// Pops an element from the back, namely 9;
	myList.pop_front();	// Pops an element from the front, namely 10;

	list <int> ::iterator it;	// So iterator is a class inside the list class!
	for (it = myList.begin(); it != myList.end(); it++) {
		cout << '\t' << *it;
		//cout << '\t' << myList.pop_front();

	}




}
