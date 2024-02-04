#include<stdio.h>
#include<stdlib.h>
struct Graph{
    int val;
    int **arr;
};
struct Graph *Create(int a){
    struct Graph *g = (struct Graph *) malloc(sizeof(struct Graph));
    g->val = a;
    g->arr = (int **) malloc(a * sizeof(int*));
    for(int i=0; i<a; i++){
        g->arr[i] = (int *) malloc(a * sizeof(int));
    }
    return g;
}
void RegisterMovement(struct Graph *g, int src, int des){
    g->arr[src][des] = 1;//Replace with weights and Reverse src and des again for Undirected Weighted 
}
void AdjMat(struct Graph *g){
    for(int i=0; i<g->val; i++){
        for(int j=0; j<g->val; j++){
            printf("%d\t",g->arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    int a, src = 0, des = 0;
    printf("Input Number of Nodes : ");
    scanf("%d" ,&a);
    struct Graph *g = Create(a);
    do{
        printf("Enter Source : ");
        scanf("%d",&src);
        printf("Enter Destination : ");
        scanf("%d",&des);
        if(src == -1 || des == -1){
            AdjMat(g);
            break;
        }
        RegisterMovement(g, src, des);
    }
    while(src != -1 || des != -1);
    return 0;
}