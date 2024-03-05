#include "linkedlist.h"

Linked::Linked() {
	headPtr = nullptr;
	tailPtr = nullptr;
}
Linked::Linked(int data) {
	Node* tempPtr = new Node;
	tempPtr->data = data;
	tempPtr->nextPtr = nullptr;
	headPtr = tempPtr;
	tailPtr = tempPtr;
}

//This is a print list function to check progress.
void Linked::print_list() {
	Node* current = headPtr;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->nextPtr;
	}
	cout << endl;
}

//Adds a new node that contains data to the end. 
//If list is empty, it sets head and tail pointers to new node.
//If it is not empty, it updates next pointer of last node to point to new node.
void Linked::push_back(int data) {
	Node* tempNode = new Node;
	tempNode->data = data;
	tempNode->nextPtr = nullptr;
	if (headPtr == nullptr) {
		headPtr = tempNode;
		tailPtr = tempNode;
	}
	else {
		tailPtr->nextPtr = tempNode;
		tailPtr = tempNode;
	}
}

//This function adds new node to the front.
//Creates new node and assigns data.
//Then, sets next pointer of new node to current head.
//Updates head pointer to point to new node.
void Linked::push_front(int data) {
	Node* tempNode = new Node;
	tempNode->data = data;
	tempNode->nextPtr = headPtr;
	headPtr = tempNode;
}

//Renoves first node from linked list.
//First checks if list is empty.
//If not empty, temporary pointer to head node is created.
//Then updates head pointer to point to next node inn list.
//Temporary pointer is then deleted.
void Linked::pop_front() {
	if (headPtr == nullptr) {
		cout << "List is empty." << endl;
	}
	else {
		Node* temp = headPtr;
		headPtr = headPtr->nextPtr;
		delete temp;
	}
}

//Removes last node from linked list.
//Checks if list is empty first.
//If not empty, checks if there is only one node in list.
//If only one node, it gets deleted and sets tail and head to null.
//If more than one node, it goes through the list to find second to last node.
//It then updates the tail pointer to point to it
//Deletes last node.
void Linked::pop_back() {
	if (headPtr == nullptr) {
		cout << "List is empty." << endl;
	}
	else {
		if (headPtr == tailPtr) {
			delete headPtr;
			headPtr = nullptr;
			tailPtr = nullptr;
		}
		else {
			Node* current = headPtr;
			while (current->nextPtr != tailPtr) {
				current = current->nextPtr;
			}
			delete tailPtr;
			tailPtr = current;
			tailPtr->nextPtr = nullptr;
		}
	}
}

//This returns the front element of the linked list.
//First checks if list is empty, and if it is it returns -1.
//Else, it returns headPtr data.
int Linked::front() {
	if (headPtr == nullptr) {
		cout << "This list is empty." << endl;
		return -1;
	}
	else {
		return headPtr->data;
	}

}

//This returns the last element in the list.
//First checks if the lisy is empty, if so returns -1.
//Else, it returns tailPtr data.
int Linked::back() {
	if (tailPtr == nullptr) {
		cout << "This list is empty." << endl;
			return -1;
	}
	else {
		return tailPtr->data;
	}
}

//Returns a boolean that represents an empty list. 
//If headPtr is null, then the list is empty and returns true.
//Else, it returns false.
bool Linked::empty() {
	if (headPtr == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//Inserts data at a chosen index in the linked list.
//First checks if index is valid.
//Checks cases for inserting at beginning at list.
//Goes through list to find node at index before chosen index.
//Creates new node, and updates pointers to include new node.
void Linked::insert(int index, int data) {
	if (index < 0) {
		cout << "Invalid index." << endl;
		return;
	}

	if (index == 0) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->nextPtr = headPtr;
		headPtr = newNode;
		if (tailPtr == nullptr) {
			tailPtr = newNode;
		}
		return;
	}

	Node* current = headPtr;
	int currentIndex = 0;

	while (current != nullptr && currentIndex < index - 1) {
		current = current->nextPtr;
		currentIndex++;
	}
	if (current == nullptr) {
		cout << "Invalid index." << endl;
		return;
	}
	Node* newNode = new Node;
	newNode->data = data;
	newNode->nextPtr = current->nextPtr;
	current->nextPtr = newNode;

	if (newNode->nextPtr == nullptr) {
		tailPtr = newNode;
	}
}

//Removes node at chosen index.
//First checks if the index is valid.
//If node at front is removes, it calls previous "pop_front" function.
//Else, it goes through list to find node at chosen index, and updates pointers.
bool Linked::remove(int index) {
	if (index < 0) {
		cout << "Invalid index." << endl;
		return false;
	}

	if (index == 0) {
		pop_front();
		return true;
	}

	Node* current = headPtr;
	Node* previous = nullptr;
	int currentIndex = 0;
	while (current != nullptr && currentIndex < index) {
		previous = current;
		current = current->nextPtr;
		currentIndex++;
	}

	if (current == nullptr) {
		cout << "Invalid index." << endl;
		return false;
	}

	previous->nextPtr = current->nextPtr;
	delete current;
	return true;
}

//Searches node with chosen data value.
//Goes through the list and compares data of each node with chosen value.
//If it is found, it returns index of the node.
//Else, -1 is returned to indicate value wasn't found.
int Linked::find(int data) {
	Node* current = headPtr;
	int index = 0;

	while (current != nullptr) {
		if (current->data == data) {
			return index;
		}
		current = current->nextPtr;
		index++;
	}

	return -1;
}