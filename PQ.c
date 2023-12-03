#include <stdio.h>
struct PQ
{
    int ele;
    int priority;
};
struct PQ p[80];
int front = -1;
int rear = -1;
void Add(int a, int b)
{
    if (front == -1)
    {
        front++;
        rear++;
        p[rear].ele = a;
        p[rear].priority = b;
    }
    else
    {
        rear++;
        p[rear].ele = a;
        p[rear].priority = b;
    }
}
int HighestPriority()
{
    int p1;
    p1 = -1;
    if (rear != -1)
    {
        for (int i = 0; i <= rear; i++)
        {
            if (p[i].priority > p1)
            {
                p1 = p[i].priority;
            }
        }
    }
    return p1;
}
void DelHighestPriority()
{
    int ele, s, m;
    s = HighestPriority();
    for (int i = 0; i <= rear; i++)
    {
        if (p[i].priority == s)
        {
            ele = p[i].ele;
            m = i;
            break;
        }
    }
    for (int j = m; j < rear; j++)
    {
        p[j].ele = p[j + 1].ele;
        p[j].priority = p[j + 1].priority;
    }
    printf("%d got Deleted\n", ele);
    rear--;
}
void Display()
{
    if (rear == 0 || rear == -1)
    {
        printf("Nothing in Queue\n");
    }
    else
    {
        for (int i = 0; i <= rear; i++)
        {
            printf("|%d|%d|-->", p[i].ele, p[i].priority);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    printf("Menu\n");
    printf("1.Insert()\n2.HighestPriority()\n3.DeleteHighestPriority()\n4.Display()");
    printf("\n5.EXIT()\n");
    do
    {
        printf("Input Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int a, b;
            printf("Input Element and Priority : ");
            scanf("%d", &a);
            scanf("%d", &b);
            Add(a, b);
        }
        else if (ch == 2)
        {
            int a = HighestPriority();
            printf("Highest Priority is %d\n", a);
        }
        else if (ch == 3)
        {
            DelHighestPriority();
        }
        else if (ch == 4)
        {
            Display();
        }
        else if (ch == 5)
        {
            printf("\n!!!EXIT!!!");
        }
        else
        {
            printf("Try Again\n");
        }
    } while (ch != 5);
    return 0;
}