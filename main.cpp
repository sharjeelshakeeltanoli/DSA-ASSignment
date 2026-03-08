#include <string>
#include "Stack.h"
#include <iostream>


int main()
{
	//task 2 part a
	string infix = "(A+B)*(C-D)+E";
	Stack<char> stack;
	string postfix = stack.Converter(infix);

	cout << "Infix Expression: " << infix << endl;
	cout << "Postfix Expression: " << postfix << endl;
	/* in the given expression
	* The program detects '(' and pushes it onto the stack															  ====|==== result = ""   ====|==== stack = (
	*
	* then it detects 'A' which is an operand so it appends it into the result string								  ====|==== result = "A"  ====|==== stack = (
	*
	* then it detects '+' and pushes it onto the stack																  ====|==== result = "A"  ====|==== stack = (+
	*
	* then it again detects an operand so it appends it into resulting string so the result string becomes "AB"       ====|==== result = "AB" ====|==== stack = (+
	*
	* then a right parenthesis appears so the program appends all operators until the left parenthesis into
	* the result string and pops them from the stack																  ====|==== result = "AB+" ====|==== stack =
	*
	* then an * operator is detected and pushed on the stack														  ====|==== result = "AB+" ====|==== stack = *
	*
	* then similar operations are performed for '('																	  ====|==== result = "AB+" ====|==== stack = *(
	*
	* then C is appended into the result string																		  ====|==== result = "AB+C" ====|==== stack = *(
	*
	* '-' operator is pushed on the stack																			  ====|==== result = "AB+C" ====|==== stack = *(-
	*
	* D is appended in the result string																			  ====|==== result = "AB+CD" ====|==== stack = *(-
	*
	* Right parenthesis detected so pop all the operators until the left parenthesis and append them into
	* the result string																								  ====|==== result = "AB+CD-" ====|==== stack = *
	*
	* '+' is tried to be pushed on the stack but because it has a lower precedence than '*' so the
	* element already in the stack is popped and appended into the string and then the + is pushed
	* onto the stack																								  ====|==== result = "AB+CD-*" ====|==== stack = +
	*
	* E is appended in the result string without any problem														  ====|==== result = "AB+CD-*E" ====|==== stack = +
	*
	* Hence the string has ended all the remaining operators stored in the stack are appended to the result string    ====|==== result = "AB+CD-*E+" ====|==== stack = (
	*/

	//task 2 part B
	postfix = "523*+9-";
	Stack<int> intStack;
	int result = intStack.Evaluate(postfix);
	cout << "\nThe Result for the expression \"5 2 3 * + 9 -\" will be : " << result << endl << endl;
	/*The evaluation will be done in the following steps
	* The string is passed to the evaluate function
	* the string is read by the program
	* it detects 5 as a number and pushes it onto the stack							  ====|==== stack = 5
	*
	* it detects 2 as a number and pushes it onto the stack							  ====|==== stack = 5 2
	*
	* it detects 3 as a number and pushes it onto the stack							  ====|==== stack = 5 2 3
	*
	* after this when it detects the operator
	* it does the operation on the top two elements and pushes the result			  ====|==== stack = 5 6  (2*3)
	* onto the stack
	*
	* similarly with + operator														  ====|==== stack = 11 (5+6)
	*
	* it detects 3 as a number and pushes it onto the stack							  ====|==== stack = 11 9
	*
	* and lastly with - operator it performs the operation and stores the
	* result in the stack															  ====|==== stack = 2 (11-9)
	*
	* final stack = 2
	*
	* then the only element remaining in the stack is the final result which is also the top element and is returned to the main function or the function call.


	*/
	return 0;
}
