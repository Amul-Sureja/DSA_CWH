#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Graph {
    int vertex;
    struct Node** adj;
    struct Queue* que;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

struct Graph* createGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertex = v;
    graph->adj = (struct Node**)malloc(v * sizeof(struct Node*));
    graph->que = createQueue();
    for (int i = 0; i < v; i++) {
        graph->adj[i] = NULL;
    }
    return graph;
}

void insertEdge(struct Graph* graph, int v, int w) {
    struct Node* newNode = createNode(w);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

void BFS(struct Graph* graph, int n) {
    int* nodes = (int*)malloc(graph->vertex * sizeof(int));
    int a = 0;
    for (int i = 0; i < graph->vertex; i++) {
        nodes[i] = 0;
    }
    nodes[n] = 1;
    enqueue(graph->que, n);
    while (graph->que->front != NULL) {
        n = dequeue(graph->que);
        printf("%d ", n);
        struct Node* temp = graph->adj[n];
        while (temp != NULL) {
            a = temp->data;
            if (nodes[a] == 0) {
                nodes[a] = 1;
                enqueue(graph->que, a);
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = createGraph(10);
    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 0, 3);
    insertEdge(graph, 1, 3);
    insertEdge(graph, 2, 4);
    insertEdge(graph, 3, 5);
    insertEdge(graph, 3, 6);
    insertEdge(graph, 4, 7);
    insertEdge(graph, 4, 5);
    insertEdge(graph, 5, 2);
    insertEdge(graph, 6, 5);
    insertEdge(graph, 7, 5);
    insertEdge(graph, 7, 8);
    printf("Breadth First Traversal for the graph is:\n");
    BFS(graph, 2);
    return 0;
}

