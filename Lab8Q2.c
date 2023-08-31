#include<stdio.h>
int largest(int arr[80]);
int main()
{
    int a;
    int b[80];
    int i;
    printf("Number of Elements \t");
    scanf("%d",&a);
    printf("Input\n");
    for (i=0; i<a; i++)
    {
        scanf("%d",&b[i]);
    }
    int l = largest(b[i]);
    printf ("Largest is %d ",l);
    return 0;
}
int largest(int arr[80])
{
    int j;
    int max;
    for(j=0; j<80; j++)
    {
        if(arr[j]>max)
        {
            max=arr[j];
        }
    }
    return max;
}