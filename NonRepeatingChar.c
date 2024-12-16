#include <stdio.h>
#include <string.h>
int* nonrepeating(char s[], int n, int *arr) {
    for (int i = 0; i < n; i++) {
        int idx = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' : s[i] - 'a' + 26;
        arr[idx] += 1;
    }
    return arr;
}
int main() {
    char str[80];
    int arr1[52] = {0};
    printf("Input String : ");
    scanf("%s", str);
    int *arr = nonrepeating(str, strlen(str), arr1);
    int max = 0, idx = 0;
    for (int i = 0; i < 52; i++) {
        if (arr[i] > max) {
            max = arr[i];
            idx = i;
        }
    }
    if (max == 0 || max == 1) {
        printf("String is pure\n");
    }
    else {
        char ch = (idx < 26) ? (char)(idx + 'A') : (char)(idx - 26 + 'a');
        printf("String is not pure\n");
        printf("Repeating Character: %c\n", ch);
    }
    return 0;
}