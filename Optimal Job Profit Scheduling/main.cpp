#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Job {
    int start, end, profit;
};

// Comparator function to sort jobs according to finish time.
bool jobComparator(Job s1, Job s2) {
    return (s1.end < s2.end);
}

// A Binary Search based function to find the latest job
// (before current job) that doesn't conflict with current job.
int latestNonConflict(vector<Job> &jobs, int index) {
    int low = 0, high = index - 1;

    // Perform binary search.
    while (low <= high) {
        int mid = (low + high) / 2;
        if (jobs[mid].end <= jobs[index].start) {
            if (jobs[mid + 1].end <= jobs[index].start)
                low = mid + 1;
            else
                return mid;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit) {
    int n = start.size();
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i] = {start[i], end[i], profit[i]};
    }

    // Sort jobs according to finish time.
    sort(jobs.begin(), jobs.end(), jobComparator);

    vector<int> dp(n);
    dp[0] = jobs[0].profit;

    // Fill the dp table in a bottom-up manner.
    for (int i = 1; i < n; i++) {
        int inclProf = jobs[i].profit;
        int l = latestNonConflict(jobs, i);
        if (l != -1) {
            inclProf += dp[l];
        }
        dp[i] = max(inclProf, dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    string inStart;
    string inEnd;
    string inProfit;
    vector<int> start;
    vector<int> end;
    vector<int> profit;
    getline(cin, inStart);
    getline(cin, inEnd);
    getline(cin, inProfit);
    stringstream x(inStart);
    stringstream y(inEnd);
    stringstream z(inProfit);
    int a;
    while(x >> a)
    {
        start.push_back(a);
    }
    while(y >> a)
    {
        end.push_back(a);
    }
    while(z >> a)
    {
        profit.push_back(a);
    }
    cout << findMaxProfit(start, end, profit);
    return 0;
}
