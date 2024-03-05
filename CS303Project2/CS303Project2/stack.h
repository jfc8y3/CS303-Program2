#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Stack {
private: 
	vector<int> elements;
public:
	Stack();
	bool empty();
	void push(int data);
	void pop();
	int top();
	int average();
	void print();
};