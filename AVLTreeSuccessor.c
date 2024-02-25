#include<stdio.h>
#include<stdlib.h>
#include"AVLTreeStructure.h"
struct Node * minValueNode(struct Node* node) {
    struct Node* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}
int findSuccessor(struct Node* root, int data) {
    struct Node* current = root;
    struct Node* successor = NULL;
    while (current != NULL) {
        if (current->data > data) {
            successor = current;
            current = current->left;
        }
        else if (current->data < data) {
            current = current->right;
        }
        else {
            if (current->right != NULL) {
                successor = minValueNode(current->right);
            }
            break;
        }
    }
    return successor->data;
}
struct Node *maxValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->right != NULL){
        current = current->right;
    }

    return current;
}
int findPredecessor(struct Node* root, int data) {
    struct Node* current = root;
    struct Node* predecessor = NULL;
    while (current != NULL) {
        if (current->data > data) {
            current = current->left;
        }
        else if(current->data < data){
            predecessor = current;
            current = current->right;
        }
        else{
            if (current->left != NULL){
                predecessor = maxValueNode(current->left);
            }
            break;
        }
    }
    return predecessor->data;
}
int main(){
    struct Node *root = NULL;
    int a, key, succ, pre;
    printf("Root Node : \n");
    do{
        printf("Input Value (Enter -1 to Exit): ");
        scanf(" %d",&a);
        if(a == -1){
        printf("Inorder traversal of AVL tree: ");
        inorder(root);
        }
        else{
            root = insert(root, a);
        }
    }while(a != -1);
    printf("\nInput Value to find Successor and Predecessor : ");
    scanf(" %d",&key);
    succ = findSuccessor(root, key);
    pre = findPredecessor(root, key);
    printf("Successor of %d : %d\n",key,succ);
    printf("Predecessor of %d : %d\n",key,pre);
    return 0;
}