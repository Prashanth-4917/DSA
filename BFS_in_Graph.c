#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Queue data structure for BFS traversal
typedef struct
{
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

// Graph data structure
typedef struct
{
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;

// Initialize the queue
void initializeQueue(Queue* q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
bool isQueueEmpty(Queue* q)
{
    return q->rear == -1;
}

// Add an element to the queue
void enqueue(Queue* q, int value)
{
    if (q->rear == MAX_NODES - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Remove an element from the queue
int dequeue(Queue* q)
{
    int item;
    if (isQueueEmpty(q))
    {
        printf("Queue is empty.\n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Initialize the graph
void initializeGraph(Graph* g, int numNodes)
{
    g->numNodes = numNodes;
    int i, j;
    for (i = 0; i < numNodes; i++)
    {
        for (j = 0; j < numNodes; j++)
        {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Add an edge to the graph
void addEdge(Graph* g, int src, int dest)
{
    if (src >= 0 && src < g->numNodes && dest >= 0 && dest < g->numNodes)
    {
        g->adjMatrix[src][dest] = 1;
        g->adjMatrix[dest][src] = 1;
    }
    else
    {
        printf("Invalid edge.\n");
    }
}

// Breadth-First Search traversal
void BFS(Graph* g, int startNode)
{
    bool visited[MAX_NODES];
    int i, current;

    for (i = 0; i < g->numNodes; i++)
    {
        visited[i] = false;
    }

    Queue q;
    initializeQueue(&q);

    visited[startNode] = true;
    enqueue(&q, startNode);

    printf("BFS traversal starting from node %d: ", startNode);

    while (!isQueueEmpty(&q))
    {
        current = dequeue(&q);
        printf("%d ", current);

        for (i = 0; i < g->numNodes; i++)
        {
            if (g->adjMatrix[current][i] == 1 && !visited[i])
            {
                enqueue(&q, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

int main()
{
    Graph graph;
    int numNodes, numEdges, i, src, dest, startNode;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    initializeGraph(&graph, numNodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges in the format (source destination):\n");
    for (i = 0; i < numEdges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    printf("Enter the starting node for BFS traversal: ");
    scanf("%d", &startNode);

    BFS(&graph, startNode);

    return 0;
}
