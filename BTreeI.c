#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};
struct Node *parent = NULL;
struct Node *newNode(int a){
    struct Node *new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data = a;
    new->right = NULL;
    new->left = NULL;
    return new;
}
void Create(struct Node *root, int a){
    struct Node *temp = root;
    while(1){
        char ch;
        printf("Left or Right of Node %d (L/R) : ",temp->data);
        scanf(" %c",&ch);
        if(ch == 'l' || ch == 'L'){
            if(temp->left == NULL){
                temp->left = newNode(a);
                break;
            }
            else{
                temp = temp->left;
            }
        }
        else if(ch == 'r' || ch == 'R'){
            if (temp->right == NULL) {
                temp->right = newNode(a);
                break;
            } 
            else {
                temp = temp->right;
            }
        }
        else{
            printf("Try Again\n");
        }
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
    int ch;
    do{
        printf("Enter Data (-1 to Exit) : ");
        scanf("%d",&ch);
        if(ch == -1){
            Print(parent);
        }
        else{
            if(parent == NULL){
                printf("\nValue of Root Node : %d\n",ch);
                parent = newNode(ch);
            }
            else{
                Create(parent, ch);
            }
        }
    }while(ch != -1);
    return 0;
}