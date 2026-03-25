#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities

int tsp(int cost[N][N], int visited[N], int currPos, int count, int costSoFar, int *minCost) {
    // If all cities are visited, return to starting city
    if (count == N && cost[currPos][0] > 0) {
        if (costSoFar + cost[currPos][0] < *minCost)
            *minCost = costSoFar + cost[currPos][0];
        return *minCost;
    }

    // Try all unvisited cities
    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[currPos][i] > 0) {
            visited[i] = 1;
            tsp(cost, visited, i, count + 1, costSoFar + cost[currPos][i], minCost);
            visited[i] = 0; // Backtrack
        }
    }

    return *minCost;
}

int main() {
    int cost[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int visited[N] = {0};
    visited[0] = 1; // Start from city 0
    int minCost = INT_MAX;

    int result = tsp(cost, visited, 0, 1, 0, &minCost);
    printf("Minimum cost of TSP = %d\n", result);

    return 0;
}