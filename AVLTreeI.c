#include <stdio.h>
#include <stdlib.h>
#include "AVLTreeStructure.h"
int main() {
    struct Node *root = NULL;
    int a;
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
    return 0;
}