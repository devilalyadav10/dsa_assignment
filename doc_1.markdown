Write a program to check if any given mathematical expression ha balanced number of
parentheses or not?
Run the program by testing following expression-
⇒a + (b − c) ∗ (d
⇒m + [a − b ∗ (c + d ∗ {m)]
⇒a + (b − c)
Hint: Use stack

## Data Structure Definition

The program uses a single data structure, a stack, implemented as a C structure named `Stack`. This structure contains a fixed-size array of 100 characters, defined by the constant `MAX`, to store parentheses such as '(', '[', and '{'. It also includes an integer variable, `top`, which tracks the index of the topmost element in the stack. Initially, `top` is set to -1 to indicate an empty stack, providing a simple and efficient way to manage parentheses during expression evaluation.
<br>
## Function Descriptions

The program includes several functions to manage the stack and check parentheses balance. The `initStack` function sets up the stack by initializing the `top` index to -1, preparing it for use. The `isEmpty` function checks if the stack is empty by returning 1 if `top` is -1, and 0 otherwise, helping to prevent underflow errors. Similarly, the `isFull` function determines if the stack is full by checking if `top` equals `MAX - 1`, returning 1 if true and 0 if not, to avoid overflow. The `push` function adds a character to the stack by incrementing `top` and storing the character at that index, but only if the stack isn’t full. The `pop` function removes and returns the top character by decrementing `top`, returning a null character ('\0') if the stack is empty. The core `isBalanced` function evaluates an expression’s parentheses by iterating through each character: it pushes opening brackets ('(', '[', '{') onto the stack and, for closing brackets (')', ']', '}'), checks that the stack isn’t empty and that the popped bracket matches the expected type. It returns 0 for any mismatch or empty stack during a pop, and 1 if the stack is empty at the end, indicating balanced parentheses.
<br>
## Main Function Overview

The `main` function orchestrates the program’s execution by testing the parentheses balance of predefined expressions. It defines an array of three test expressions as strings and sets a variable to track the number of expressions (3). Using a loop, it iterates through each expression, calls the `isBalanced` function to check its parentheses, and prints the expression followed by "Balanced: Yes" if the function returns 1, or "Balanced: No" if it returns 0. The function concludes by returning 0 to signal successful program completion.
<br>
## Sample Output

When the program runs, it processes the test expressions and produces the following output:
<br>
```
Expression: a + (b - c) * (d
Balanced: No

Expression: m + [a - b * (c + d * {m)]
Balanced: No

Expression: a + (b - c)
Balanced: Yes
```

This output clearly indicates whether each expression has properly matched parentheses, with the first two being unbalanced due to missing or mismatched closing brackets, and the third being balanced.
