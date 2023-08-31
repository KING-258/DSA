#include <stdio.h>
void main(){
   int n;
   char str[100][100],s[100];
   printf("Enter number of names :");
   scanf("%d",&n);
   printf("Enter names in any order:");
   for(int i=0;i<n;i++)
   {
      scanf("%s",str[i]);
   }
   for(int i=0;i<n;i++)
   {
      for(int j=i+1;j<n;j++)
      {
         if(strcmp(str[i],str[j])>0)
         {
            strcpy(s,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],s);
         }
      }
   }
   printf(" \nThe sorted order of names are:\n");
   for(int i=0;i<n;i++)
   {
      printf("\t%s\t",str[i]);
   }
}