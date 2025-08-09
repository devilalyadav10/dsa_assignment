#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, char item)
{
    if (!isFull(s))
        s->items[++s->top] = item;
}

char pop(Stack *s)
{
    if (!isEmpty(s))
        return s->items[s->top--];
    return '\0';
}

int isBalanced(char *exp)
{
    Stack s;
    initStack(&s);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(&s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(&s))
                return 0;
            char top = pop(&s);
            if ((exp[i] == ')' && top != '(') ||
                (exp[i] == ']' && top != '[') ||
                (exp[i] == '}' && top != '{'))
                return 0;
        }
    }
    return isEmpty(&s);
}

int main()
{
    char *exps[] = {"a + (b - c) * (d", "m + [a - b * (c + d * {m)]", "a + (b - c)"};
    int n = 3;
    for (int i = 0; i < n; i++)
    {
        printf("Expression: %s\n", exps[i]);
        printf("Balanced: %s\n\n", isBalanced(exps[i]) ? "Yes" : "No");
    }
    return 0;
}