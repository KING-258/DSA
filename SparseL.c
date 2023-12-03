#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int n;
    struct Node *ptr;
};
struct Node *temp;
struct Node *first;
void Send(int a)
{
    struct Node *temp = malloc(sizeof(struct Node));
    temp->n = a;
    temp->ptr = NULL;
    if (first != NULL)
    {
        temp->ptr = first;
    }
    first = temp;
}
void PRINT()
{
    struct Node *temp = first;
    printf("List is \n");
    while (temp != NULL)
    {
        printf("%d\t", temp->n);
        temp = temp->ptr;
    }
    printf("\n");
}
int main()
{
    int a;
    int arr[80][80];
    int c = 0;
    printf("Input Array Size\n");
    scanf("%d", &a);
    printf("Input Elements\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (arr[i][j] != 0)
            {
                c++;
            }
        }
    }
    printf("Number of Values is %d \n", c);
    first = NULL;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (arr[i][j] != 0)
            {
                Send(arr[i][j]);
            }
        }
    }
    PRINT();
    return 0;
}