#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int rc;
    int lc;
};
struct Node *parent = NULL;
struct Node *Create(int a){
    if(a == -1){
        return NULL;
    }
    else{
        struct Node *t;
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = a;
        printf("Left of %d Node : ", t->data);
        scanf("%d",&a);
        if(a == -1){
            t->lc = -1;
        }
        else{
            t->lc = 1;
        }
        t->left = Create(a);
        printf("Right of %d Node : ",t->data);
        scanf("%d",&a);
        if(a != -1){
            t->rc = 1;
        }
        else{
            t->rc = -1;
        }
        t->right = Create(a);
        return t;
    }
}
void InOrder(struct Node *root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d| %d| %d ",root->data, root->rc, root->lc);
        InOrder(root->right);
    }
}
void PreOrder(struct Node *root){
    if(root != NULL){
        printf("%d| %d| %d ",root->data, root->rc, root->lc);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(struct Node *root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d| %d| %d ",root->data, root->rc, root->lc);
    }
}
void Print(struct Node *root){
    printf("\nInOrder Traversal ------> \n");
    InOrder(root);
    printf("\nPreOrder Traversal ------> \n");
    PreOrder(root);
    printf("\nPostOrder Traversal -------> \n");
    PostOrder(root);
}
int main(){
    int a;
    printf("Value of Root Node (Enter -1 for NULL): ");
    scanf("%d",&a);
    parent = Create(a);
    Print(parent);
    return 0;
}