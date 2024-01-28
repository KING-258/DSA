#include<stdio.h>
#include<stdlib.h>
int *arr;
int main(){
    int n;
    printf("Enter Number of Elements for the Array : ");
    scanf("%d",&n);
    arr = (int *) malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        printf("Enter element at %d : ",(i+1));
        scanf("%d",&arr[i]);
    }
    printf("Sorted Array is ---->\n");
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}