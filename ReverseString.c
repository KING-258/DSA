#include<stdio.h>
#include<string.h>
void reverse(char s[], int n, char str[]){
    int j = 0;
    for(int i=n-1; i>=0; i--){        
        str[j] = s[i];
        j++;
        
    }
    str[j] = '\0';
}
int main(){
    char str[80], ans[80];
    printf("Input String : ");
    scanf("%s",&str);
    reverse(str, strlen(str), ans);
    printf("Reverse of String : %s",ans);
    return 0;
}