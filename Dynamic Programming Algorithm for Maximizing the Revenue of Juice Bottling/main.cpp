#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> maxRevenueBottling(const vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n, 0); // dp[i] will hold the max revenue for i units of juice
    vector<int> solution(n, 0); // To reconstruct the solution

    // Compute maximum revenue for each amount of juice
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[i] < prices[j] + dp[i - j]) {
                dp[i] = prices[j] + dp[i - j];
                solution[i] = j; // Store the last added quantity
            }
        }
    }

    // Reconstruct the solution
    vector<int> quantities;
    int remaining = n - 1;
    while (remaining > 0) {
        quantities.push_back(solution[remaining]);
        remaining -= solution[remaining];
    }

    // Since we want the quantities in ascending order
    sort(quantities.begin(), quantities.end());

    return quantities;
}

int main() {
    vector<int> prices;
    string line;
    getline(cin, line);
    stringstream s(line);
    int x;
    while(s >> x)
    {
      prices.push_back(x);
    }

    vector<int> quantities = maxRevenueBottling(prices);

    for (int quantity : quantities) {
        cout << quantity << " ";
    }

    return 0;
}
