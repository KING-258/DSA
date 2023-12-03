#include <stdio.h>
#include <stdlib.h>
struct DOB
{
    int day;
    int *month;
    int year;
};
struct STU_INFO
{
    int reg_no;
    char *name[80];
    int year;
};
struct COLLEGE
{
    char *college_name[80];
    char uni_name[80];
};
struct Student
{
    struct DOB;
    struct STU_INFO;
    struct COLLEGE;
};
int main()
{
    struct Student s;
    return 0;
}