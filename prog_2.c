#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int item) { s->items[++s->top] = item; }
int pop(Stack *s) { return s->items[s->top--]; }
int peek(Stack *s) { return s->items[s->top]; }

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack s;
    initStack(&s);
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit(infix[i]))
        {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[k++] = pop(&s);
            pop(&s);
        }
        else
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i]))
                postfix[k++] = pop(&s);
            push(&s, infix[i]);
        }
    }
    while (!isEmpty(&s))
        postfix[k++] = pop(&s);
    postfix[k] = '\0';
}

int evaluatePostfix(char *postfix)
{
    Stack s;
    initStack(&s);
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(&s, postfix[i] - '0');
        }
        else
        {
            int b = pop(&s);
            int a = pop(&s);
            switch (postfix[i])
            {
            case '+':
                push(&s, a + b);
                break;
            case '-':
                push(&s, a - b);
                break;
            case '*':
                push(&s, a * b);
                break;
            case '/':
                push(&s, a / b);
                break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    char infix[] = "5+2*3";
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}
