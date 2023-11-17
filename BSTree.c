#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* right;
    struct Node* left;
};
struct Node *parent = NULL;
struct Node* Create(struct Node *root, int data){
    if(root == NULL){
        root = (struct Node*) malloc(sizeof(struct Node));
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    else{
        if(data < root->data){
            root->left = Create(root->left, data);
        }
        else if(data > root->data){
            root->right = Create(root->right, data);
        }
        else{
            printf("Duplicates Not Allowed\n");
        }
        return root;
    }
}
void InOrder(struct Node *root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
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
    printf("\nInOrder Traversal ------> \n");
    InOrder(root);
    printf("\nPreOrder Traversal ------> \n");
    PreOrder(root);
    printf("\nPostOrder Traversal -------> \n");
    PostOrder(root);
}
int main(){
    int a;
    printf("Root Node (Enter -1 to Exit)");
    do
    {
        printf("Value for Node : ");
        scanf("%d",&a);
        if(a == -1){
            Print(parent);
        }
        parent = Create(parent, a);
    }while(a != -1);
    return 0;
}