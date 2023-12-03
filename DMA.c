#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    int *ptr;
    printf("Number of Elements\t");
    scanf("%d", &a);
    ptr = (int *)malloc(a * sizeof(int));
    printf("Input\n");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("Array\t");
    for (int i = 0; i < a; i++)
    {
        printf("%d\t", ptr[i]);
    }
    return 0;
}