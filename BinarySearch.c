#include <stdio.h>
#include <stdlib.h>
int *arr;
int size;
int binarySearch(int key) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int key;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    printf("Enter elements of the array in sorted order:\n");
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    int result = binarySearch(key);
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}