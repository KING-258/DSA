#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define MAX 10
int minCost;
int assignment[MAX];
int n;
void printAssignment() {
    printf("Assigned Jobs:\n");
    for (int i = 0; i < n; i++) {
        printf("Worker %d -> Job %d\n", i + 1, assignment[i] + 1);
    }
}
void calculateCost(int cost[MAX][MAX]) {
    int tempCost = 0;
    for (int i = 0; i < n; i++) {
        tempCost += cost[i][assignment[i]];
    }
    if (tempCost < minCost)
        minCost = tempCost;
}
void assignJobs(int cost[MAX][MAX], int i) {
    if (i == n) {
        calculateCost(cost);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (cost[i][j] != -1) {
            assignment[i] = j;
            assignJobs(cost, i + 1);
        }
    }
}
int main() {
    int cost[MAX][MAX];
    printf("Enter the number of workers/jobs: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    minCost = INT_MAX;
    clock_t start = clock();
    assignJobs(cost, 0);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Minimum Cost: %d\n", minCost);
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}