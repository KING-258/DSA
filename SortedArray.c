#include<stdio.h>
int main(){
    int a, flag = 0;
    printf("Enter Size of Array : ");
    scanf("%d",&a);
    int arr[a];
    for(int i=0; i<a; i++){
        printf("Input Element at %d : ",(i+1));
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<a-1; i++){
        if(arr[i]<=arr[i+1]){
            flag = 1;
        }
        else{
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        printf("Not Sorted");
    }
    else{
        printf("Sorted");
    }
    return 0;
}