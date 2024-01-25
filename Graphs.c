#include<stdio.h>
#include<stdlib.h>
struct Node{
    char val;
    struct Node *next;
};
void Add(struct Node *head, char a){
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->val = a;
    temp->next = NULL;
    struct Node *t;
    t = head;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = temp;
}
void Print(struct Node *head){
    struct Node *temp = head;
    printf("%c->",temp->val);
    temp = temp->next;
    while(temp != NULL){
        printf(" |%c| ",temp->val);
        temp = temp->next;
    }
}
struct Graph{
    char name;
    struct Node *list;
};
int main(){
    int n, out;
    struct Graph *g;
    printf("Number of Nodes in Graph : ");
    scanf("%d",&n);
    g = (struct Graph *) malloc(n * sizeof(struct Graph));
    for(int i=0; i<n; i++){
        printf("Name for Node %d of Graph : ",(i+1));
        scanf(" %c",&g[i].name);
        g[i].list = (struct Node *) malloc(sizeof(struct Node));
        g[i].list->val = g[i].name;
        g[i].list->next = NULL;
    }
    for(int i=0; i<n; i++){
        printf("OutDegree for %c : ",g[i].name);
        scanf(" %d",&out);
        for(int j=0; j<out; j++){
            char a;
            printf("Input %d for %c : ",(j+1),g[i].name);
            scanf(" %c",&a);
            Add(g[i].list, a);
        }
    }
    printf("Graph----->\n");
    for(int i=0; i<n; i++){
        Print(g[i].list);
        printf("\n");
    }
    return 0;
}