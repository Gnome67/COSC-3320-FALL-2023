#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int minPalindromePartition(const string& s) {
    int n = s.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    vector<int> minCut(n);

    for (int i = 0; i < n; ++i) {
        minCut[i] = i;  // maximum cuts
        for (int j = 0; j <= i; ++j) {
            if (s[i] == s[j] && (i - j < 2 || isPalindrome[j + 1][i - 1])) {
                isPalindrome[j][i] = true;
                minCut[i] = (j == 0) ? 0 : min(minCut[i], minCut[j - 1] + 1);
            }
        }
    }

    return minCut[n - 1] + 1; // add 1 as minCut gives cuts, not the number of partitions
}

int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    cout << minPalindromePartition(s) << endl;

    return 0;
}

