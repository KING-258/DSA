#include <stdio.h>
#define MAX 10
int n;
void inputCostMatrix(int costMatrix[MAX][MAX]) {
    printf("Enter the number of workers/tasks (maximum 10): ");
    scanf("%d", &n);
    printf("Enter the cost matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }
}
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void copyArray(int src[], int dest[]) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}
int calculateCost(int assignment[], int costMatrix[MAX][MAX]) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}
void bruteForce(int costMatrix[MAX][MAX]) {
    int assignment[MAX];    
    int currentAssignment[MAX];
    int minCost = __INT_MAX__;
    int totalPermutations = factorial(n);
    for (int i = 0; i < totalPermutations; i++) {
        for (int j = 0; j < n; j++) {
            assignment[j] = j;
        }
        int k = n - 2;
        while (k >= 0 && assignment[k] > assignment[k + 1]) {
            k--;
        }
        if (k < 0) break;
        int l = n - 1;
        while (assignment[k] > assignment[l]) {
            l--;
        }
        swap(&assignment[k], &assignment[l]);
        int i = k + 1, j = n - 1;
        while (i < j) {
            swap(&assignment[i], &assignment[j]);
            i++;
            j--;
        }
        int currentCost = calculateCost(assignment, costMatrix);
        if (currentCost < minCost) {
            minCost = currentCost;
            copyArray(assignment, currentAssignment);
        }
    }
    printf("Optimal Assignment: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", currentAssignment[i] + 1);
    }
    printf("\nMinimum Cost: %d\n", minCost);
}
int main() {
    int costMatrix[MAX][MAX];
    inputCostMatrix(costMatrix);
    bruteForce(costMatrix);
    return 0;
}