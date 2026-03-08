#include <iostream>
#include "Stack.h"



int precedenceCheck(char c)
{
	//gives score/rating to the operators based on their precedence
	if (c == '^')
	{
		return 3;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else //invalid characters check
	{
		return -1;
	}
}

template<class ItemType>
string Stack<ItemType>::Converter(string s)
{
	Stack<char> st; //Initialization for the stack
	string result; //variable to store the result string(converted)
	char dummy;	//Just used as an argument for the pop function no real usage can be neglected
	for (int i = 0; i < s.length(); i++) //To iterate through the whole string
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))  //this detects if the character is an operand (could've used isalpha() as well)
		{
			result += s[i]; //if it is an operand put it straight into the result string 
		}
		else if (s[i] == '(') //Detect left parenthesis
		{
			st.Push(s[i]); //Push it on the stack
		}
		else if (s[i] == ')') //Detect right paranthesis
		{
			while (!st.IsEmpty() && st.Top() != '(') //To iterate through the whole stack until the stack is empty or left parenthesis is found
			{
				result += st.Top(); //until the stack is empty or left parenthesis is found keep on appending top element in the result string
				st.Pop(dummy); //pop the top element
			}
			if (!st.IsEmpty())
			{
				st.Pop(dummy); // Pop '(' 
			}
		}
		else
		{
			while (!st.IsEmpty() && precedenceCheck(st.Top()) >= precedenceCheck(s[i])) //For operators first the operators go throught the precedenceCheck function and then come here
			{
				result += st.Top(); //if the precedence of the operator at the Top is greater than the precedence of the incoming operator append the Top operator append the top element in the result string
				st.Pop(dummy); //pop the top element
			}
			st.Push(s[i]); //now when the precedence of the top operator is less than the precedence of the incoming operator push it onto the stack
		}
	}
	//The part of the code below appends all the remaining operators present in the stack to the result string and pops them
	while (!st.IsEmpty())
	{
		result += st.Top(); 
		st.Pop(dummy);
	}
	//return the result string to the main we could've printed it here as well but it is not the best practice
	return result;
}


