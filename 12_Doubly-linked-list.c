#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node from the list
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = *head;
    struct Node *prevNode = NULL;

    // If the key is found at the head node
    if (current->data == key)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return;
    }

    // Traverse the list to find the node to delete
    while (current != NULL && current->data != key)
    {
        prevNode = current;
        current = current->next;
    }

    // If the key is not found
    if (current == NULL)
    {
        printf("Key not found\n");
        return;
    }

    // Adjust the pointers to delete the node
    prevNode->next = current->next;
    if (current->next != NULL)
        current->next->prev = prevNode;

    free(current);
}

// Function to print the doubly linked list
void printList(struct Node *head)
{
    printf("Doubly linked list: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the doubly linked list implementation
int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printList(head);

    deleteNode(&head, 20);
    deleteNode(&head, 40);

    printList(head);

    return 0;
}
