#include <stdio.h>
#include <string.h>
void letter(const char *word) {
    char nword[50];
    int flag;
    for(int i=0; i<strlen(word); i++){
        flag = 0;
        for(int j=65; j< 91; j++){
            nword[i] = (char) j;
            printf("%s\n",nword);
            if((char) j == word[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            continue;
        }
        for(int j=97; j< 123; j++){
            nword[i] = (char) j;
            printf("%s\n",nword);
            if((char) j == word[i]){
                break;
            }
        }
    }
}
int main() {
    char word[50];
    printf("Input Word: ");
    scanf("%s", word);
    letter(&word);
    return 0;
}