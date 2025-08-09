# Infix to Postfix Conversion and Evaluation Documentation

## Data Structure Definition
- **Stack**: Struct with a character array `items` (size 100) and integer `top`.

## Functions Implemented
- `initStack(Stack *s)`: Initializes stack with `top` = -1.
- `isEmpty(Stack *s)`: Checks if stack is empty.
- `isFull(Stack *s)`: Checks if stack is full.
- `push(Stack *s, char item)`: Pushes character to stack.
- `pop(Stack *s)`: Pops top character.
- `precedence(char op)`: Returns operator precedence (1 for +,-; 2 for *,/).
- `infixToPostfix(char *infix, char *postfix)`: Converts infix to postfix using stack.
- `evaluatePostfix(char *postfix)`: Evaluates postfix expression using stack.

## Main Method Organization
- Takes sample infix expression `"5+2*3"`.
- Converts to postfix and evaluates.
- Prints infix, postfix, and result.

## Sample Output
```
Infix: 5+2*3
Postfix: 523*+
Result: 11
```