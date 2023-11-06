#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *right, *left;
} *parent = NULL;
struct Node *Create(){
    struct Node *t;
    int a;
    printf("Value for Node : ");
    scanf("%d",&a);
    if (a == -1)
    {
        return NULL;
    }
    else{
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = a;
        printf("Data for Left of %d Node : ",t->data);
        t->left = Create();
        printf("Data for Right of %d Node : ",t->data);
        t->right = Create();
        return t;
    }
}
void InOrder(struct Node *root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
    else{
        return;
    }
}
void PreOrder(struct Node *root){
    if(root != NULL){
        PreOrder(root->left);
        printf("%d ",root->data);
        PreOrder(root->right);
    }
    else{
        return;
    }
}
void PostOrder(struct Node *root){
    if(root != NULL){
        PostOrder(root->left);
        printf("%d ",root->data);
        PostOrder(root->right);
    }
    else{
        return;
    }
}
void Print(struct Node *root){
    int c;
    printf("\n1.InOrder() 2.PreOrder() 3.PostOrder() 4.Exit() (1/2/3/4) : ");
    do
    {
        scanf("%d",&c);
        if(c == 1){
            InOrder(root);
        }
        else if(c == 2){
            PreOrder(root);
        }
        else if(c == 3){
            PostOrder(root);
        }
        else if(c == 4){
            printf("!!!Exit!!!");
        }
        else{
            printf("Try Again");
        }
    } while (c != 4);
}
int main(){
    printf("Enter the Value for the Root Node and -1 for NULL : ");
    parent = Create();
    Print(parent);
    return 0;
}