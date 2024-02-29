#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to implement stack
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

// Stack operations
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char *infix, char *postfix)
{
    struct Stack *stack = createStack(strlen(infix));
    int i, k;
    for (i = 0, k = -1; infix[i]; ++i)
    {
        if (isOperand(infix[i]))
            postfix[++k] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && stack->array[stack->top] != '(')
                postfix[++k] = pop(stack);
            if (!isEmpty(stack) && stack->array[stack->top] != '(')
                return; // Invalid expression
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->array[stack->top]))
                postfix[++k] = pop(stack);
            push(stack, infix[i]);
        }
    }
    while (!isEmpty(stack))
        postfix[++k] = pop(stack);
    postfix[++k] = '\0';
}

int main()
{
    char infix[MAX_SIZE] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);
    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
