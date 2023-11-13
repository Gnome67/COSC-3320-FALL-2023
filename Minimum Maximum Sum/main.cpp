#include<bits/stdc++.h>
using namespace std;

int ans = INT_MAX;

void solve(vector<int>& a, int j, vector<int>& bags) {
    if(j == a.size()) {
        ans = min(ans, *max_element(bags.begin(), bags.end()));
        return;
    }
    for(int i = 0; i < bags.size(); i++) {
        bags[i] += a[j];
        if (bags[i] < ans) // pruning
            solve(a, j + 1, bags);
        bags[i] -= a[j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());  // sort in descending order

    vector<int> bags(k, 0);
    solve(a, 0, bags);
    cout << ans;
}
