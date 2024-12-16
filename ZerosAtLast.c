#include<stdio.h>
int* zerosatlast(int *arr,int n, int *arr1){
    int j=0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr1[j] = arr[i];
            j++ ;
        }
        else{
            count += 1;
        }
    }
    for(int i=j; i<=n; i++){
        arr[i] = 0;
    }
    return arr1;
}
int main(){
    int a;
    printf("Input Size of Array : ");
    scanf("%d",&a);
    int arr[a], ans[a];
    for(int i=0; i<a; i++){
        printf("Input the Elements at %d: ",(i+1));
        scanf("%d",&arr[i]);
    }
    int* res = zerosatlast(arr, a, ans);
    for(int i=0; i<a; i++){
        printf("%d\t",res[i]);
    }
    return 0;
}