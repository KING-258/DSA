#include<stdio.h>
#include<stdlib.h>
int *arr, opcount = 0;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int s){
    for(int i=0; i<s; i++){
        for(int j=0; j<s-i-1; j++){
            if(arr[j] > arr[j+1]){
                opcount++;
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
int main(){
    int n;
    printf("Enter Number of elements for Array : ");
    scanf("%d",&n);
    arr = (int *) malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        printf("Entry for Array at %d : ",(i+1));
        scanf("%d",&arr[i]);
    }
    BubbleSort(n);
    printf("Sorted Array using BubbleSort : ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\nOPCOUNT = %d\n",opcount);
    return 0;
}