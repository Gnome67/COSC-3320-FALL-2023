#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int maxDifference(vector<int> question)
// {
//     int minimum = question[0];
// 		int maximum = 0;
//     for(int i=1;i<question.size();i++)
//     {
//       maximum = max(maximum,question[i]-minimum);
//       minimum = min(question[i],minimum);
//     }
//     return maximum;
// }

int maxDifference(const vector<int>& arr, int low, int high) {
    if (low == high) { return 0; }
    if (high == low + 1) { return max(0, arr[high] - arr[low]); }

    int mid = (low + high) / 2;
    int maxDiffLeft = maxDifference(arr, low, mid);
    int maxDiffRight = maxDifference(arr, mid + 1, high);
    int minLeft = *min_element(arr.begin() + low, arr.begin() + mid + 1);
    int maxRight = *max_element(arr.begin() + mid + 1, arr.begin() + high + 1);
    int maxCrossDiff = maxRight - minLeft;

    return max({maxDiffLeft, maxDiffRight, maxCrossDiff});
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) { cin >> arr[i]; }
    cout << maxDifference(arr, 0, n - 1) << endl;
    return 0;
}
