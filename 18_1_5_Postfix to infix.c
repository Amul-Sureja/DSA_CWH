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

void postfixToInfix(char *postfix, char *infix)
{
    struct Stack *stack = createStack(strlen(postfix));
    int length = strlen(postfix);
    int i, j = 0;
    char op1, op2;
    for (i = 0; i < length; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(stack, postfix[i]);
        }
        else
        {
            op1 = pop(stack);
            op2 = pop(stack);
            infix[j++] = '(';
            infix[j++] = op2;
            infix[j++] = postfix[i];
            infix[j++] = op1;
            infix[j++] = ')';
            infix[j] = '\0';
            push(stack, infix[j - 1]);
            push(stack, infix[j - 3]);
        }
    }
}

int main()
{
    char postfix[MAX_SIZE] = "ab+c*";
    char infix[MAX_SIZE];
    postfixToInfix(postfix, infix);
    printf("Postfix expression: %s\n", postfix);
    printf("Infix expression: %s\n", infix);
    return 0;
}
