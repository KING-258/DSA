#include<stdio.h>
#include<stdlib.h>
struct NODE {
    char name[20];
};
struct Graph {
    int node;
    int adjMatrix[80][80];
    struct NODE NODEList[80];
};
struct Graph createGraph(int node) {
    struct Graph g;
    g.node = node;
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            g.adjMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < node; i++) {
        printf("Enter name for NODE %d: ", i);
        scanf("%s", g.NODEList[i].name);
    }
    return g;
}
void addEdge(struct Graph *g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}
void createEdges(struct Graph *g) {
    int src, dest;
    printf("Enter Source and Destination(0 to Node -1) (-1 -1 to Terminate) : ");
    scanf("%d %d", &src, &dest);
    if (src == -1 && dest == -1)
        return;
    addEdge(g, src, dest);
    createEdges(g);
}
void displayAdjMatrix(struct Graph g) {
    printf("Adjacency Matrix:\n");
    printf("\t");
    for (int i = 0; i < g.node; i++) {
        printf("%s\t", g.NODEList[i].name);
    }
    printf("\n");
    for (int i = 0; i < g.node; i++) {
        printf("%s\t", g.NODEList[i].name);
        for (int j = 0; j < g.node; j++) {
            printf("%d\t", g.adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int node;
    printf("Enter the number of node: ");
    scanf("%d", &node);

    struct Graph g = createGraph(node);

    createEdges(&g);

    displayAdjMatrix(g);

    return 0;
}