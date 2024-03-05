#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	int size;
	Node* nextPtr;
};

class Linked {
private:
	Node* headPtr;
	Node* tailPtr;
public:
	Linked();
	Linked(int data);
	void print_list();
	void push_back(int data);
	void push_front(int data);
	void pop_front();
	void pop_back();
	int front();
	int back();
	bool empty();
	void insert(int index, int data);
	bool remove(int index);
	int find(int data);
};