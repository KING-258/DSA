#include <stdio.h>
#include <stdlib.h>
struct Node
{
          int data;
          struct Node *next;
};
struct Node *first1 = NULL, *first2 = NULL, *temp, *t;
void Add1(int a)
{
          temp = (struct Node *)malloc(sizeof(struct Node));
          temp->data = a;
          temp->next = NULL;
          struct Node *ptr;
          ptr = first1;
          if (first1 == NULL)
          {
                    first1 = temp;
          }
          else
          {
                    while (ptr->next != NULL)
                    {
                              ptr = ptr->next;
                    }
                    ptr->next = temp;
          }
}
void Add2(int a)
{
          temp = (struct Node *)malloc(sizeof(struct Node));
          temp->data = a;
          temp->next = NULL;
          struct Node *ptr;
          ptr = first2;
          if (first2 == NULL)
          {
                    first2 = temp;
          }
          else
          {
                    while (ptr->next != NULL)
                    {
                              ptr = ptr->next;
                    }
                    ptr->next = temp;
          }
}
void Add1a2()
{
          temp = first1;
          while (temp->next != NULL)
          {
                    temp = temp->next;
          }
          temp->next = first2;
}
void Sort()
{
          temp = first1;
          while (temp->next != NULL)
          {
                    t = temp->next;
                    while (t != NULL)
                    {
                              if (temp->data > t->data)
                              {
                                        int st = temp->data;
                                        temp->data = t->data;
                                        t->data = st;
                              }
                              t = t->next;
                    }
                    temp = temp->next;
          }
}
void DisplayR()
{
          t = first1;
          while (t != NULL)
          {
                    printf("|%d|-->", t->data);
                    t = t->next;
          }
          printf("NULL\n");
}
void Display1()
{
          t = first1;
          while (t != NULL)
          {
                    printf("|%d|-->", t->data);
                    t = t->next;
          }
          printf("NULL\n");
}
void Display2()
{
          t = first2;
          while (t != NULL)
          {
                    printf("|%d|-->", t->data);
                    t = t->next;
          }
          printf("NULL\n");
}
int main()
{
          int a, b, s;
          printf("Class A Size : ");
          scanf("%d", &a);
          printf("Class B Size : ");
          scanf("%d", &b);
          printf("Input for Class A : \n");
          for (int i = 0; i < a; i++)
          {
                    printf("Input %d ", (i + 1));
                    int ele;
                    scanf("%d", &ele);
                    Add1(ele);
          }
          printf("Input for Class B : \n");
          for (int i = 0; i < b; i++)
          {
                    printf("Input %d ", (i + 1));
                    int ele;
                    scanf("%d", &ele);
                    Add2(ele);
          }
          printf("Class A : \n");
          Display1();
          printf("Class B : \n");
          Display2();
          Add1a2();
          Sort();
          printf("Merged and Sorted Class : \n");
          DisplayR();
          return 0;
}