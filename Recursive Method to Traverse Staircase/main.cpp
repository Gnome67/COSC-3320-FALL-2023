#include <iostream>
#include <vector>

using namespace std;

int countWaysToClimbStairs(int height, int maxSteps)
{
    vector<int> dp(height + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= height; i++) { for (int j = 1; j <= maxSteps && i - j >= 0; j++) { dp[i] += dp[i - j]; } }
    return dp[height];
}

int main()
{
    int height, maxSteps;
    cin >> height >> maxSteps;
    int ways = countWaysToClimbStairs(height, maxSteps);
    cout << ways;
    return 0;
}
