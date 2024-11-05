#include <iostream>
#include "linkedList.h"
#include "unorderedLinkedList.h"

using namespace std;

void print(nodeType<int> *head);
void destroy(nodeType<int> *&head, nodeType<int> *&tail);
void insert(nodeType<int> *&head, nodeType<int> *&tail, int *newItem);

int main(){


nodeType<int> *head = nullptr;
nodeType<int> *tail = nullptr;

int *newInt = new int;
cout << "Enter a new number: (-999) to exit ";
cin >> *newInt;


	while (*newInt != -999){

	insert(head, tail, newInt);
	newInt = new int;
	cout << "Enter a number: ";
	cin >> *newInt;

}
delete newInt; // special case for the sentinel value

print(head);
destroy(head,tail);


return 0;
}

void insert(nodeType<int> *&head, nodeType<int>*& tail,int *newItem){
//nodeType<int> *newNode; // .data segment and is used in the creation of a new node
//newNode = new nodeType<int>();

// Create a new node
nodeType<int>* newNode = new nodeType<int>();

newNode->data = newItem;
newNode->next = nullptr;
//head = newNode;
//Insert the new node into the Linked List
//Case #1 Empty List

if(head == nullptr){
	head = newNode;
	tail = newNode;
}
else{
		tail->next = newNode;
		tail = newNode;
}
return;
}

void print(nodeType<int> *head){
	//Traverse a linked list
	cout << "Print List" << endl;
	nodeType<int> *current;
	current = head;
	while(current != nullptr){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
return;
}

void destroy(nodeType<int> *&head, nodeType<int> *&tail){
	//Traveres a Linked List
	nodeType<int> *current;
	current = head;
	
	nodeType<int> *previous;
	previous = nullptr;

	while(current != nullptr){
	previous = current; // back pointer
	delete current;
	current = current->next;
	delete previous;
}
head = nullptr;
tail = head;

return;
}

