#include<stdio.h>
int BoundarySum(int arr[][80], int a, int b);
int main()
{
    int r, c;
    int a[80][80];
    int b[80][80];
    int flag=1;
    int temp;
    int sum;
    int number;

    printf("Number of Rows\t");
    scanf("%d",&r);
    printf("Number of Columns\t");
    scanf("%d",&c);
    printf("Input Matrix");
    printf("\n");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            b[i][j]=a[i][j];
        }
    }
    printf("Matrix \n");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d \t",b[i][j]);   
        }
        printf("\n");
    }

    printf("Condition");
    printf("\n");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            int n=a[i][j];
            sum=0;
            temp=n;
            for(int b=1; b<n; b++)
            {
                if(n%b==0)
                {
                    sum+=b;
                }
            }
            if(sum==temp)
            {
                flag=0;
                printf("%d is Perfect \n",temp);
                printf("\n");
            }
            else
            {
                flag=1;
                printf("%d is Not Perfect\n",temp);
                printf("\n");
            }
        }
    }
    int cs;
    cs=a[0][0]+a[r-1][c-1]+a[r-1][0]+a[0][c-1];
    printf("Corner Sum \n %d",cs);
    printf("\n");
    printf("\n Replacing Perfect Numbers with Cornersum \n");
    for(int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            int t=a[i][j];
            sum=0;
            temp=t;
            for(int b=1; b<t; b++)
            {
                if(t%b==0)
                {
                    sum+=b;
                }
            }
            if (sum==temp)
            {
                a[i][j]=cs;
            }
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }

    int bs;
    bs =BoundarySum(b, r, c);
    printf("Boundary Sum is %d ",(bs-cs));
    printf("\n\n\n");
    for(int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            int t=b[i][j];
            sum=0;
            temp=t;
            for(int g=1; g<t; g++)
            {
                if(t%g==0)
                {
                    sum+=g;
                }
            }
            if (sum==temp)
            {
                b[i][j]=bs-cs;
            }
        }
    }

    printf("\n \n \n \nReplacing with BoundarySum \n");
    for(int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            printf("%d \t",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int BoundarySum(int arr[][80], int a ,int b)
{
    int x=0;
    for (int i=0; i<a; i++)
    {
        x=x+arr[i][0];
    }
    int y=0;
    for (int j=0;j<b;j++)
    {
        y=y+arr[0][j];
    }
    int z=0;
    for (int k=0; k<b; k++) 
    {
        z=z+arr[a-1][k];
    }   
    int w=0;
    for (int l=0; l<a; l++)
    {
        w=w+arr[l][b-1];
    }
    int s;
    s= x+y+z+w;
    return s;
}