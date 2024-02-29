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

void prefixToPostfix(char *prefix, char *postfix)
{
    struct Stack *stack = createStack(strlen(prefix));
    int length = strlen(prefix);
    int i, j = 0;
    for (i = length - 1; i >= 0; --i)
    {
        if (isOperand(prefix[i]))
        {
            postfix[j++] = prefix[i];
        }
        else
        {
            char op1 = pop(stack);
            char op2 = pop(stack);
            postfix[j++] = op1;
            postfix[j++] = op2;
            postfix[j++] = prefix[i];
            push(stack, postfix[j - 1]);
            push(stack, postfix[j - 2]);
        }
    }
    postfix[j] = '\0';
}

int main()
{
    char prefix[MAX_SIZE] = "-*+a/bc*def";
    char postfix[MAX_SIZE];
    prefixToPostfix(prefix, postfix);
    printf("Prefix expression: %s\n", prefix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
