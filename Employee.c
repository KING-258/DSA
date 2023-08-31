#include<stdio.h>
#include<stdlib.h>
struct Employee
{
          char name[80];
          char address[80];
          int date, month, year;
};
struct Employee Input(struct Employee e)
{
          printf("Name\t");
          scanf("%s",&e.name);
          printf("DOB Date Month and Year\n");
          scanf("%d",&e.date);
          scanf("%d",&e.month);
          scanf("%d",&e.year);
          printf("Address\n");
          scanf("%s",&e.address);
          return e;
}
void Print(struct Employee e)
{
          printf("\n%s is born on %d-%d-%d and lives at %s\n",e.name, e.date, e.month, e.year, e.address);
}
int main()
{
          int n;
          struct Employee *e1 = NULL;
          printf("Input N\t");
          scanf("%d",&n);
          e1 = (struct Employee *) malloc(n * sizeof(struct Employee));
          printf("Input\n");
          for(int i=0; i<n; i++)
          {
                    e1[i] = Input(e1[i]);
          }
          printf("Display");
          for(int i=0; i<n; i++)
          {
                    Print(e1[i]);
          }
          return 0;
}