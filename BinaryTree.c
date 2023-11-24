#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *Create(){
    int a;
    struct Node *t = (struct Node *) malloc(sizeof(struct Node));
    printf("Data for this Node : ");
    scanf("%d",&a);
    if(a == -1){
        return NULL;
    }
    else{
        t->data = a;
        printf("Left of %d Node\n",t->data);
        t->left = Create();
        printf("Right of %d Node\n",t->data);
        t->right = Create();
        return t;
    }
}
void Inorder(struct Node *root){
    if(root != NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
void PreOrder(struct Node *root){
    if(root != NULL){
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void PostOrder(struct Node *root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}
void Print(struct Node *root){
    printf("InOrder : \n");
    Inorder(root);
    printf("\nPreOrder : \n");
    PreOrder(root);
    printf("\nPostOrder : \n");
    PostOrder(root);
}
int main(){
    struct Node *parent = NULL;
    printf("Root Node (Input -1 for NULL) : ");
    parent = Create();
    Print(parent);
    return 0;
}