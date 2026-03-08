#include "Stack.h"
#include <string>
#include<iostream>


using namespace std;


template <class ItemType>
int Stack<ItemType>::Evaluate(string s)
{
	Stack<int>stk; //an integer stack
	int dummy; //only used as an argument for pop no real usage
	for (int i = 0; i < s.length(); i++) //to iterate thorugh the whole string 's'
	{
		char ch = s[i]; //assign the character present at the ongoing loop number to ch 
		if (isdigit(ch)) //To check if the character ch is a digit or an operator 
		{ 
			//if it is a numeric digit 
			stk.Push(ch - '0'); //converts character into integer using ASCII 
			//for example ch='7'
			//ASCII for '7' is 55
			//And ASCII for '0' is 48
			//So 55 - 48 = 7
		}
		else
		{
			//if the character is not a number and is an operator
			int val1, val2; //two variables
			val1 = stk.Top(); //first variable will contain the number stored at the top of the stack (first number)
			stk.Pop(dummy); //Pop the top element
			val2 = stk.Top(); //second variable will contain the number stored at the top of the stack (second number)
			stk.Pop(dummy); //Pop the top element

			switch (ch)
			{
			case '+':
				stk.Push(val1 + val2); //if the operator is '+' add the first two numbers and push the result in the stack
				break;
			case '-':
				stk.Push(val2 - val1);//if the operator is '-' push the difference in the stack
				break;
			case '*':
				stk.Push(val2 * val1); //if the operator is '*' multiply the first two numbers and push the result in the stack
				break;
			case '/': 
				stk.Push(val2 / val1); //if the operator is '/' divide the first two numbers and push the result in the stack 
				break;
			}
		}
		//after this loop the stack will only contain the final result of all the operations done 
	}
	return stk.Top(); //return the top element which is the final result
}


