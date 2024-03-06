#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
};

struct Graph
{
    int V;
    struct LinkedList *array;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct LinkedList *)malloc(V * sizeof(struct LinkedList));
    for (int i = 0; i < V; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void DFSUtil(struct Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->array[vertex].head;
    while (temp != NULL)
    {
        int n = temp->data;
        if (!visited[n])
        {
            DFSUtil(graph, n, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph *graph, int vertex)
{
    int *visited = (int *)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
    {
        visited[i] = 0;
    }
    DFSUtil(graph, vertex, visited);
}

int main()
{
    int V = 8;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 2);

    printf("Depth First Traversal for the graph is: ");
    DFS(graph, 0);

    return 0;
}
