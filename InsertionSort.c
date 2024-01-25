#include<stdio.h>
#include<stdlib.h>
int *arr;
void InsertionSort(int n){
    for(int i=0; i<n; i++){
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main(){
    int n;
    printf("Enter Number of Elements for the Array : ");
    scanf("%d",&n);
    arr = (int *) malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        printf("Enter element at %d : ",(i+1));
        scanf("%d",&arr[i]);
    }
    InsertionSort(n);
    printf("Sorted Array is ---->\n");
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}