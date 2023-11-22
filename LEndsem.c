#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *right;
    struct Node *left;
};
int a1[80];
int m = 0, j=0;
struct Node *parent1 = NULL, *parent2 = NULL, *BST = NULL;
struct Node *Create(){
    struct Node *t;
    int a;
    t = (struct Node *) malloc(sizeof(struct Node));
    printf("Value of the Node : ");
    scanf("%d",&a);
    if(a == -1){
        return NULL;
    }
    else{
        t->data = a;
        a1[j] = a;
        j++;
        printf("Data for Left of %d Node : ",t->data);
        t->left = Create();
        printf("Data for Right of %d Node : ",t->data);
        t->right = Create();
        return t;
    }
}
struct Node* Construct(struct Node *root, int data){
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
        return root;
    }
}
int Largest(struct Node *root, struct Node *n){
    if(root == NULL){
        printf("Empty Tree\n");
    }
    else{
        int left, right, curr;
        curr = n->data;
        if(n->left != NULL){
            left = Largest(root, n->left);
            if(left > curr){
                curr = left;
            }
        }
        if(n->right != NULL){
            right = Largest(root, n->right);
            if(right > curr){
                curr = right;
            }
        }
        return curr;
    }
}
void InOrder(struct Node *root){
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}
int main(){
    printf("Root Node of 1st Tree (Input -1 for NULL)\n");
    parent1 = Create();
    printf("Root Node of 2nd Tree (Input -1 for NULL)\n");
    parent2 = Create();
    int l1, l2;
    l1 = Largest(parent1, parent1);
    l2 = Largest(parent2, parent2);
    int s;
    if(l1 > l2){
        s = l1;
    }
    else{
        s = l2;
    }
    a1[++j] = -1;
    int k = 0;
    BST = Construct(BST, s);
    do{
        int m = a1[k];
        if(m == -1){
            InOrder(BST);
        }
        else{
            BST = Construct(BST, m);
        }
        k++;
    }while(m != -1);
    return 0;
}