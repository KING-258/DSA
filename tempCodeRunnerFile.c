#include <stdio.h>
int main(){ int a[100];int n;int i;int j;printf("No. of Elements");scanf("%d",&n);for(i=0; i<n; i++){scanf("%d",&a[i]);}for(j=0; j<n; j++){printf("%d",a[j]);printf("\n");}return 0;}