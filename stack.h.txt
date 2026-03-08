#pragma once
#include <string>

using namespace std;

template<class ItemType>
class Stack {
public:
	Stack();
	Stack(int max); // PARAMETERIZED CONSTRUCTOR
	~Stack(); // DESTRUCTOR
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(ItemType newItem);
	void Pop(ItemType& item);
	ItemType Top() const; // Added to access top element
	string Converter(string s);
	int Evaluate(string s);
private:
	int top;
	int maxStack;
	ItemType* items; // DYNAMIC ARRAY
};

template class Stack<int>;
template class Stack<char>;