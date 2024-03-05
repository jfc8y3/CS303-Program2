#include <iostream>
#include "linkedlist.h"
#include "stack.h"
using namespace std;

int main() {
	char DSchoice;
	cout << "Choose your data structure:" << endl;
	cout << "Stack: S" << endl;
	cout << "Linked List: L" << endl;
	cout << "Enter choice: ";
	cin >> DSchoice;

    //If user chooses stack, it runs the main loop of this option.

    if (DSchoice == 's' || DSchoice == 'S') {
        Stack myStack;
        cout << endl;
        cout << "You chose stack." << endl;
        while (true) {
            char Schoice;
            cout << endl;
            cout << "Check if stack is empty: E" << endl;
            cout << "Push values onto stack: P" << endl;
            cout << "Remove element from stack: R" << endl;
            cout << "Find top of stack: T" << endl;
            cout << "Find average of values in stack: A" << endl;
            cout << "Print stack: S" << endl;
            cout << "Enter choice: ";
            cin >> Schoice;
            if (Schoice == 'e' || Schoice == 'E') {
                cout << endl;
                if (myStack.empty()) {
                    cout << "This stack is empty." << endl;
                }
                else {
                    cout << "This stack has values." << endl;
                }
            }
            else if (Schoice == 'p' || Schoice == 'P') {
                int value;
                cout << endl;
                cout << "Enter value to push onto stack: ";
                cin >> value;
                myStack.push(value);
                cout << endl;
            }
            else if (Schoice == 'r' || Schoice == 'R') {
                cout << endl;
                myStack.pop();
                cout << endl;
            }
            else if (Schoice == 't' || Schoice == 'T') {
                cout << endl;
                if (!myStack.empty()) {
                    cout << "Top of stack: " << myStack.top() << endl;
                }
                cout << endl;
            }
            else if (Schoice == 'a' || Schoice == 'A') {
                cout << endl;
                if (!myStack.empty()) {
                    cout << "Average of values in stack: " << myStack.average() << endl;
                }
                cout << endl;
            }
            else if (Schoice == 's' || Schoice == 'S') {
                cout << endl;
                myStack.print();
                cout << endl;
            }
        }
    }

    //If user chooses a linkeed list, this is the main loop of that option.

    if (DSchoice == 'l' || DSchoice == 'L') {
        Linked myList;
        cout << endl;
        cout << "You chose linked list." << endl;
        while (true) {
            char Lchoice;
            cout << endl;
            cout << "Print the list: P" << endl;
            cout << "Push value to the back of the list: B" << endl;
            cout << "Push value to the front of the list: F" << endl;
            cout << "Pop value from the front of the list: O" << endl;
            cout << "Pop value from the back of the list: K" << endl;
            cout << "Get the front value of the list: T" << endl;
            cout << "Get the back value of the list: A" << endl;
            cout << "Check if the list is empty: E" << endl;
            cout << "Insert value at index in the list: I" << endl;
            cout << "Remove value at index from the list: R" << endl;
            cout << "Find index of value in the list: N" << endl;
            cout << "Enter choice: ";
            cin >> Lchoice;
            if (Lchoice == 'p' || Lchoice == 'P') {
                cout << endl;
                cout << "Printing the list:" << endl;
                myList.print_list();
            }
            else if (Lchoice == 'b' || Lchoice == 'B') {
                int value;
                cout << endl;
                cout << "Enter value to push to the back: ";
                cin >> value;
                myList.push_back(value);
            }
            else if (Lchoice == 'f' || Lchoice == 'F') {
                int value;
                cout << endl;
                cout << "Enter value to push to the front: ";
                cin >> value;
                myList.push_front(value);
            }
            else if (Lchoice == 'o' || Lchoice == 'O') {
                cout << endl;
                myList.pop_front();
            }
            else if (Lchoice == 'k' || Lchoice == 'K') {
                cout << endl;
                myList.pop_back();
            }
            else if (Lchoice == 't' || Lchoice == 'T') {
                cout << endl;
                cout << "Front value of the list: " << myList.front() << endl;
            }
            else if (Lchoice == 'a' || Lchoice == 'A') {
                cout << endl;
                cout << "Back value of the list: " << myList.back() << endl;
            }
            else if (Lchoice == 'e' || Lchoice == 'E') {
                cout << endl;
                if (myList.empty()) {
                    cout << "The list is empty." << endl;
                }
                else {
                    cout << "The list is not empty." << endl;
                }
            }
            else if (Lchoice == 'i' || Lchoice == 'I') {
                int index, value;
                cout << endl;
                cout << "Enter index to insert at: ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                myList.insert(index, value);
            }
            else if (Lchoice == 'r' || Lchoice == 'R') {
                int index;
                cout << endl;
                cout << "Enter index to remove: ";
                cin >> index;
                myList.remove(index);
            }
            else if (Lchoice == 'n' || Lchoice == 'N') {
                int value;
                cout << endl;
                cout << "Enter value to find: ";
                cin >> value;
                int index = myList.find(value);
                if (index != -1) {
                    cout << "Value " << value << " found at index " << index << " in the list." << endl;
                }
                else {
                    cout << "Value " << value << " not found in the list." << endl;
                }
            }
        }
    }

}