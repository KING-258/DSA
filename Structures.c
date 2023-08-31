#include<stdio.h>
struct Student{
    int rollno;
    int age;
}s0= {25,22};
int main()
{
    struct Student s1={20,21};
    struct Student s2;
    s2.rollno=32;
    printf("%d",s2.rollno);
    printf("%d",s0.age);
    return 0;
}