#include <stdio.h>
#include <stdlib.h>
void Reverse(int *ptr, int a)
{
    int temp = 0;
    for (int i = 0; i < a / 2; i++)
    {
        temp = ptr[i];
        ptr[i] = ptr[a - i - 1];
        ptr[a - i - 1] = temp;
    }
}
int main()
{
    int a;
    int *ptr = NULL;
    printf("Size of 1D Array\t");
    scanf("%d", &a);
    printf("Input\n");
    ptr = (int *)malloc((a + 1) * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &ptr[i]);
    }
    Reverse(ptr, a);
    printf("Reversed Array\n");
    for (int i = 0; i < a; i++)
    {
        printf("%d\t", *(ptr + i));
    }
    return 0;
}