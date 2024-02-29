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

void prefixToInfix(char *prefix, char *infix)
{
    struct Stack *stack = createStack(strlen(prefix));
    int length = strlen(prefix);
    int i, j;
    for (i = length - 1; i >= 0; --i)
    {
        if (isOperand(prefix[i]))
        {
            char temp[2] = {prefix[i], '\0'};
            push(stack, temp[0]);
        }
        else
        {
            char op1 = pop(stack);
            char op2 = pop(stack);
            infix[0] = '(';
            infix[1] = op1;
            infix[2] = prefix[i];
            infix[3] = op2;
            infix[4] = ')';
            infix[5] = '\0';
            push(stack, infix[0]);
            j = 1;
            while (infix[j] != '\0')
            {
                push(stack, infix[j]);
                j++;
            }
        }
    }
}

int main()
{
    char prefix[MAX_SIZE] = "-*+a/bc*def";
    char infix[MAX_SIZE];
    prefixToInfix(prefix, infix);
    printf("Prefix expression: %s\n", prefix);
    printf("Infix expression: %s\n", infix);
    return 0;
}
