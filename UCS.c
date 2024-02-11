#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"
int cost = 999999;
void UCS(struct Graph *graph, int start, int end, int V, char *path) {
    int visited[V];
    memset(visited, 0, sizeof(visited));
    struct PQNode {
        int vertex;
        int cost;
    };
    struct PQNode pq[V];
    int pqSize = 0;
    int pathIndex = 0;
    int parent[V];
    memset(parent, -1, sizeof(parent));
    pq[pqSize].vertex = start;
    pq[pqSize].cost = 0;
    pqSize++;
    while (pqSize > 0) {
        int u = pq[0].vertex;
        int ucost = pq[0].cost;
        for (int i = 0; i < pqSize - 1; i++) {
            pq[i] = pq[i + 1];
        }
        pqSize--;
        if (visited[u]) continue;
        visited[u] = 1;
        if (u == end) {
            cost = ucost;
            path[pathIndex++] = u + '0';
            int current = end;
            while (current != start) {
                path[pathIndex++] = '-';
                path[pathIndex++] = parent[current] + '0';
                current = parent[current];
            }
            path[pathIndex] = '\0';
            int len = strlen(path);
            for (int i = 0; i < len / 2; i++) {
                char temp = path[i];
                path[i] = path[len - i - 1];
                path[len - i - 1] = temp;
            }
            return;
        }
        struct Node *temp = graph[u].list;
        while (temp != NULL) {
            int v = temp->val;
            int w = temp->weight;
            if (!visited[v]) {
                pq[pqSize].vertex = v;
                pq[pqSize].cost = ucost + w;
                pqSize++;
                parent[v] = u;
            }
            temp = temp->next;
        }
        for (int i = 0; i < pqSize - 1; i++) {
            for (int j = i + 1; j < pqSize; j++) {
                if (pq[i].cost > pq[j].cost) {
                    struct PQNode temp = pq[i];
                    pq[i] = pq[j];
                    pq[j] = temp;
                }
            }
        }
    }
}
int main(){
    int a, src = 0, des = 0, wg = -1, start, end;
    printf("Enter Number of Vertices : ");
    scanf("%d",&a);
    struct Graph g[a];
    char *path;
    path = (char *) malloc(a * sizeof(char));
    for(int i=0; i<a; i++){
        printf("Enter Name for Vertice %d : ",(i+1));
        scanf("%s",&g[i].name);
        g[i].list = (struct Node *) malloc(sizeof(struct Node));
        g[i].list->val = i;
        g[i].list->weight = 0;
    }
    do{
        for(int i=0; i<a; i++){
            printf("%s ---> %d\n",g[i].name,g[i].list->val);
        }
        printf("Input Source (-1 to Exit) : ");
        scanf("%d",&src);
        printf("Input Destination (-1 to Exit): ");
        scanf("%d",&des);
        printf("Input Weight for this Movement (0 to Exit): ");
        scanf("%d",&wg);
        if(src == -1 || des == -1 || wg == 0){
            printf("\nNot an APT Option\n");
        }
        else{
            Add(g[src].list, des, wg);
        }
    }while(src !=  -1 && des != -1);
    for(int i=0; i<a; i++){
        Print(g[i].list);
    }
    printf("Input Starting Vertex : ");
    scanf(" %d",&start);
    printf("Input Goal Vertex : ");
    printf(" %d",&end);
    UCS(g, start, end, a, path);
    printf("\nCost is %d following Path : %s",cost,path);
    return 0;
}