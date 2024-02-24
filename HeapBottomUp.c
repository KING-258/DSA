#include <stdio.h>
#include <stdlib.h>
struct Heap {
    int *arr;
    int cid;
    int size;
};
struct Heap *heap;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int getparent(int idx) {
    return (idx - 1) / 2;
}
void minheapify(int idx) {
    int s = idx;
    int ls = 2 * idx + 1;
    int rs = 2 * idx + 2;
    if (ls < heap->cid && heap->arr[ls] < heap->arr[s]) {
        s = ls;
    }
    if (rs < heap->cid && heap->arr[rs] < heap->arr[s]) {
        s = rs;
    }
    if (s != idx) {
        swap(&heap->arr[s], &heap->arr[idx]);
        minheapify(s);
    }
}
void maxheapify(int idx) {
    int l = idx;
    int ls = 2 * idx + 1;
    int rs = 2 * idx + 2;
    if (ls < heap->cid && heap->arr[ls] > heap->arr[l]) {
        l = ls;
    }
    if (rs < heap->cid && heap->arr[rs] > heap->arr[l]) {
        l = rs;
    }
    if (l != idx) {
        swap(&heap->arr[l], &heap->arr[idx]);
        maxheapify(l);
    }
}
void Initialise(int *arr, int size, int ch) {
    heap = (struct Heap *)malloc(sizeof(struct Heap));
    heap->size = size;
    heap->arr = (int *)malloc(size * sizeof(int));
    heap->cid = size;
    for (int i = 0; i < size; i++) {
        heap->arr[i] = arr[i];
    }
    for (int i = (size - 1) / 2; i >= 0; i--) {
        if(ch == 1){
            minheapify(i);
        }
        else{
            maxheapify(i); 
        }
    }
}
int minhroot() {
    if (heap->cid <= 0) {
        return -1;
    }
    int mroot = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->cid];
    minheapify(0);
    return mroot;
}
int maxhroot() {
    if (heap->cid <= 0) {
        return -1;
    }
    int mroot = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->cid];
    maxheapify(0);
    return mroot;
}
void PrintMin() {
    while (heap->cid > 0) {
        printf("%d ", minhroot());
    }
    printf("\n");
}
void PrintMax() {
    while (heap->cid > 0) {
        printf("%d ", maxhroot());
    }
    printf("\n");
}
int main() {
    int size, a;
    printf("Input Total Capacity of Heap : ");
    scanf("%d", &size);
    int *elements = (int *)malloc(size * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &elements[i]);
    }
    Initialise(elements, size, 1);
    printf("MinHeap ----->\n");
    PrintMin();
    Initialise(elements, size, 2);
    printf("MaxHeap ----->\n");
    PrintMax();
    return 0;
}