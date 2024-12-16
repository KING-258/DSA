#include<stdio.h>
int maxproduct(int arr[], int n){
    int l1=0, l2=-1;
    int s1=-1, s2=0;
    for(int i=0; i<n; i++){
        if(arr[i] >= l1){
            l2 = l1;
            l1 = arr[i];
        }
        if(arr[i] <= s1){
            s2 = s1;
            s1 = arr[i];
        }
    }
    int a = l1*l2;
    int b = s1*s2;
    return (a > b) ? a : b;
}
int main(){
    int a;
    printf("Input size of the Array : ");
    scanf("%d",&a);
    int arr[a];
    printf("Input Elements for the Array : \n");
    for(int i=0; i<a; i++){
        scanf("%d",&arr[i]);
    }
    int ans = maxproduct(arr, a);
    printf("Max Product in Array : %d",ans);
    return 0;
}