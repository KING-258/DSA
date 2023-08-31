#include<stdio.h>
#include<stdlib.h>
struct Student
{
          char name[80];
          int roll;
          float cgpa;
};
struct Student Input(struct Student s)
{
          printf("Input Name \t");
          scanf("%s",&s.name);
          printf("Input Roll No. \t");
          scanf("%d",&s.roll);
          printf("Input GPA \t");
          scanf("%f",&s.cgpa);
          return s;
}
int main()
{
          int a;
          struct Student *s1 = NULL;
          printf("Number of Students\t");
          scanf("%d",&a);
          s1 = (struct Student *) malloc(a * sizeof(struct Student));
          for(int i=0; i<a; i++)
          {
                    s1[i] = Input(s1[i]);
          }
          for(int i=0; i<a; i++)
          {
                    for(int j=i+1; j<a; j++)
                    {
                              if(s1[i].roll > s1[j].roll)
                              {
                                        struct Student temp;
                                        temp = s1[i];
                                        s1[i] = s1[j];
                                        s1[j] = temp;
                              }
                    }
          }
          printf("Ascending Order according to Roll No.\n");
          for(int i=0; i<a; i++)
          {
                    printf("Name : %s\n",s1[i].name);
                    printf("Roll : %d\n",s1[i].roll);
                    printf("CGPS : %f\n",s1[i].cgpa);
                    printf("\n");
          }
          return 0;
}