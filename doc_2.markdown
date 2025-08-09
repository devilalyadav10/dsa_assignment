Write a program to convert an infix mathematical expression to postfix and evaluate it.

## Data Structure Definition

The program defines a stack data structure, implemented as a C structure named Stack, to handle the conversion of infix expressions to postfix and their evaluation. This structure includes a fixed-size array of 100 integers, set by the constant MAX, to store digits and operators during processing. It also contains an integer variable, top, initialized to -1 to indicate an empty stack, which tracks the index of the topmost element, enabling efficient push and pop operations for managing expression elements.

## Function Descriptions

The program implements several functions to manage the stack and perform infix-to-postfix conversion and evaluation. The initStack function initializes the stack by setting top to -1, preparing it for use. The isEmpty function checks if the stack is empty by returning 1 if top is -1, and 0 otherwise, preventing underflow. The push function adds an integer to the stack by incrementing top and storing the item at that index. The pop function removes and returns the top integer, decrementing top, while peek returns the top integer without removing it, aiding in operator precedence checks. The precedence function assigns priority levels to operators: 1 for addition and subtraction, 2 for multiplication and division, and 0 for others, guiding the conversion process. The infixToPostfix function converts an infix expression to postfix by scanning each character: digits are directly appended to the output, opening parentheses are pushed onto the stack, closing parentheses trigger popping operators until an opening parenthesis is found, and operators are pushed after popping higher or equal precedence operators from the stack, with remaining stack contents appended at the end. The evaluatePostfix function computes the result of a postfix expression by pushing digits (converted from characters) onto the stack and, for each operator, popping two operands, applying the operation (addition, subtraction, multiplication, or division), and pushing the result back, with the final result popped from the stack.

## Main Function Overview

The main function orchestrates the program by processing a single infix expression, such as "5+2\*3". It defines a character array for the infix expression and another for the postfix result. It calls infixToPostfix to convert the infix expression to postfix, then prints both the infix and postfix expressions. Finally, it calls evaluatePostfix to compute the result of the postfix expression and prints it, returning 0 to indicate successful execution.

## Sample Output

When the program runs with the infix expression "5+2\*3", it produces the following output:
<br>
```
Infix: 5+2*3
Postfix: 523*+
Result: 11
```

This output shows the original infix expression, its postfix equivalent (indicating 5 and 2 are multiplied first, then added to 3), and the evaluated result, correctly computed as (2 \* 3) + 5 = 11.
