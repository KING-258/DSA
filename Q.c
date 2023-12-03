#include <stdio.h>
#include <stdlib.h>
int q[80] = {0};
int front = -1;
int rear = -1;
void Enqueue(int a)
{
    if (rear == -1)
    {
        front++;
    }
    rear++;
    q[rear] = a;
}
void Dequeue()
{
    if (front > rear)
    {
        printf("Not Possible\n");
    }
    else
    {
        int a;
        a = q[front];
        front++;
        printf("%d removed from Front\n", a);
    }
}
void Display()
{
    printf("\nQueue is : \n");
    for (int i = front; i <= rear; i++)
    {
        printf("| %d |", q[i]);
    }
}
int main()
{
    int ch;
    front = -1;
    rear = -1;
    printf("Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Input Choice ");
    scanf("%d", &ch);
    do
    {
        if (ch == 1)
        {
            int d;
            printf("Input Element to Add\t");
            scanf("%d", &d);
            Enqueue(d);
        }
        else if (ch == 2)
        {
            Dequeue();
        }
        else if (ch == 3)
        {
            Display();
        }
        else if (ch == 4)
        {
            printf("Exiting");
            exit(0);
        }
        else
        {
            printf("Input Valid Choice");
        }
        printf("\nInput Choice\t");
        scanf("%d", &ch);
    } while (ch != 4);
    return 0;
}