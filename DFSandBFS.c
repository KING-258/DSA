#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_NODES 100
struct Node {
    int data;
    struct Node* next;
};
struct Graph {
    struct Node* adjList[MAX_NODES];
    bool visited[MAX_NODES];
    char vertexNames[MAX_NODES][20];
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
        strcpy(graph->vertexNames[i], "");
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}
void dfs(struct Graph* graph, int vertex) {
    struct Node* temp = graph->adjList[vertex];
    graph->visited[vertex] = true;
    printf("%s ", graph->vertexNames[vertex]);
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!graph->visited[adjVertex]) {
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }
}
void bfs(struct Graph* graph, int start) {
    struct Node* queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = createNode(start);
    graph->visited[start] = true;
    while (front < rear) {
        struct Node* currentNode = queue[front++];
        printf("%s ", graph->vertexNames[currentNode->data]);
        struct Node* temp = graph->adjList[currentNode->data];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!graph->visited[adjVertex]) {
                queue[rear++] = createNode(adjVertex);
                graph->visited[adjVertex] = true;
            }
            temp = temp->next;
        }
    }
}
void printAdjList(struct Graph* graph, int vertices) {
    int i;
    printf("\nAdjacency List:\n");
    for (i = 0; i < vertices; ++i) {
        printf("%s -> ", graph->vertexNames[i]);
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%s -> ", graph->vertexNames[temp->data]);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    struct Graph* graph = createGraph();
    int v1, v2, start_vertex, vertices = 0;
    char name[20];
    printf("Enter the vertices and their names (format: vertex name, end with -1): \n");
    int vertex = 0;
    do {
        scanf("%d", &v1);
        if (v1 == -1)
            break;
        scanf("%s", name);
        strcpy(graph->vertexNames[v1], name);
        vertex++;
    } while (vertex < MAX_NODES);
    printf("Enter the edges (format: v1 v2, end with -1 -1): \n");
    while (true) {
        scanf("%d %d", &v1, &v2);
        if (v1 == -1 || v2 == -1)
            break;
        addEdge(graph, v1, v2);
        vertices = (v1 > vertices) ? v1 : vertices;
        vertices = (v2 > vertices) ? v2 : vertices;
    }
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start_vertex);
    printf("Depth First Traversal: ");
    dfs(graph, start_vertex);
    for (int i = 0; i < MAX_NODES; ++i) {
        graph->visited[i] = false;
    }
    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &start_vertex);
    printf("Breadth First Traversal: ");
    bfs(graph, start_vertex);
    printAdjList(graph, vertices + 1);
    return 0;
}