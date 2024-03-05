#include "stack.h"

Stack::Stack() {}

//Checks if stack is empty by comparing element vector size to 0.
bool Stack::empty() {
	if (elements.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

//Uses vector push back function to add to the stack.
void Stack::push(int data) {
	elements.push_back(data);
}

//First checks if stack is empty.
//If not, it uses the vector pop back function.
void Stack::pop() {
	if (elements.size() == 0) {
		cout << "The stack is empty.";
	}
	else {
		elements.pop_back();
	}
}

//First checks if stack is empty.
//If not, it uses the vector back function.
int Stack::top() {
	if (elements.size() == 0) {
		cout << "The stack is empty.";
		return -1;
	}
	else {
		return elements.back();
	}
}

//Finds the average by adding all elements in stack, anf divides by vector size.
int Stack::average() {
	if (elements.size() == 0) {
		cout << "The stack is empty." << endl;
		return -1;
	}
	else {
		int sum = 0;
		for (int i = 0; i < elements.size(); i++) {
			sum = sum + elements[i];
		}

		return (sum / elements.size());

	}
}

//This function prints out the elements backwards, so it is visually a "stack"
void Stack::print() {
	if (elements.size() == 0) {
		cout << "The stack is empty." << endl;
	}
	else {
		for (int i = elements.size() - 1; i >= 0; i--) {
			cout << elements[i] << endl;
		}
	}
}