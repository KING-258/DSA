#include<stdio.h>
struct CQ{
          int a;
          int arr[80];
          int front;
          int rear;
};
void Initialise(struct CQ *s)
{
          s->front = -1;
          s->rear = -1;
}
void Push(struct CQ *s, int ad)
{
          if(s->rear == -1)
          {
                    s->front++;
                    s->arr[++s->rear] = ad;
          }
          else if((s->rear+s->front) == s->a)
          {
                    printf("Queue is Full\n");
          }
          else
          {
                    s->rear++;
                    s->arr[s->rear] = ad;
          }
}
void Pop(struct CQ *s)
{
          if (s->rear >= s->front)
          {
                    printf("%d removed from front\n",s->arr[s->front]);
                    s->front++;
          }
          else{
                    printf("Nothing in Queue\n");
          }
}
void Display(struct CQ *s)
{
          for(int i=s->front; i<=s->rear; i++)
          {
                    printf("|%d|",s->arr[i]);
          }
          printf("\n");
}
int main()
{
          int n,ch;
          struct CQ s1, s2;
          Initialise(&s1);
          Initialise(&s2);
          printf("Input N size of the Array : ");
          scanf("%d",&n);
          s1.a = n/2 - 1;
          s2.a = n - s1.a - 2;
          printf("Menu\n1.PushinCQ1()\n2.PushinCQ2()\n");
          printf("3.PopfromCQ1()\n4.PopfromCQ2()\n");
          printf("5.DisplayCQ1()\n6.DisplayCQ2()\n");
          printf("7.Exit()\n");
          do
          {
                    printf("Input Choice : ");
                    scanf("%d",&ch);
                    if(ch == 1)
                    {
                              int k;
                              printf("Input Element to Add : ");
                              scanf("%d",&k);
                              Push(&s1, k);
                    }
                    else if(ch == 2)
                    {
                              int k;
                              printf("Input Element to Add : ");
                              scanf("%d",&k);
                              Push(&s2, k);
                    }
                    else if (ch == 3)
                    {
                              Pop(&s1);
                    }
                    else if (ch == 4)
                    {
                              Pop(&s2);
                    }
                    else if (ch == 5)
                    {
                              printf("CQ1\n");
                              Display(&s1);
                    }
                    else if (ch == 6)
                    {
                              printf("CQ2\n");
                              Display(&s2);
                    }
                    else if(ch == 7)
                    {
                              printf("!!!Exit!!!");
                    }
                    else{
                              printf("Try Again\n");
                    }
          }while (ch!=7);
          int arr[n];
          for (int i = 0; i < n/2; i++)
          {
                    arr[i] = s1.arr[s1.front + i];
                    arr[i+s1.rear+1] = s2.arr[s2.front + i];
          }
          arr[n-1] = s2.arr[s2.rear];
          printf("\nArray is \n");
          for(int i=0; i<=n-1; i++)
          {
                    printf("%d ",arr[i]);
          }
          return 0;
}