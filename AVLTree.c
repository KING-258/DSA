#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};
int *arr, id = 0;
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
int* Sort(int a, int *b){
    for(int i=0; i<a; i++){
        for(int j=i+1; j<a; j++){
            if(b[i] > b[j]){
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    return b;
}
int Middle(int a){
    int m;
    if(a % 2 == 0){
        m = a/2;
    }
    else{
        m = a/2 + 1;
    }
    return m;
}
int main(){
    int a;
    printf("Input data in an array Format\n");
    printf("Size of the Array : ");
    scanf("%d",&a);
    arr = (int *) malloc((a+1) * sizeof(int));
    printf("Input Data for the Array : \n");
    for(int i=0; i<a; i++){
        scanf("%d",&arr[i]);
    }
    arr = Sort(a, arr);
    printf("Sorted Array : ");
    for(int i=0; i<a; i++){
        printf("%d ",arr[i]);
    }
    int s, i0 = 0;
    arr[a] = -1;
    int m = Middle(a);
    parent = Create(parent, arr[m]);
    do{
        s = arr[i0];
        if(s == -1){
            Print(parent);
        }
        parent = Create(parent, s);
        i0++;
    }while(s != -1);
    return 0;
}