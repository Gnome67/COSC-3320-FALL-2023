#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    vector<vector<int>> cost(m, vector<int>(n));

    // Reading the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Initialize the cost matrix
    for (int i = 0; i < m; ++i) {
        cost[i][0] = matrix[i][0];
    }

    // Dynamic programming to calculate the cost
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            int up = cost[(i - 1 + m) % m][j - 1];
            int left = cost[i][j - 1];
            int down = cost[(i + 1) % m][j - 1];
            cost[i][j] = matrix[i][j] + min({up, left, down});
        }
    }

    // Find the minimum cost in the last column
    int minCost = cost[0][n - 1];
    for (int i = 1; i < m; ++i) {
        minCost = min(minCost, cost[i][n - 1]);
    }

    cout << minCost;

    return 0;
}
