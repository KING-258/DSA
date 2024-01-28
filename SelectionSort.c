#include<stdio.h>
#include<stdlib.h>
int *arr;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int n){
    int minpos;
    for(int i=0; i<n; i++){
        minpos = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minpos]){
                minpos = j;
            }
            if(minpos != i){
                swap(&arr[minpos], &arr[i]);
            }
        }
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
    SelectionSort(n);
    printf("Sorted Array is ---->\n");
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}