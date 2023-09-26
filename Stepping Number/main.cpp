#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool isStepNum(int n)
// {
//     int prevDigit = -1;
//     while (n)
//     {
//         int curDigit = n % 10;
//         if (prevDigit == -1) { prevDigit = curDigit; }
//         else { if (abs(prevDigit - curDigit) != 1) { return false; } }
//         prevDigit = curDigit;
//         n /= 10;
//     }
//     return true;
// }

// void displaySteppingNumbers(int n, int m) { for (int i=n; i<=m; i++) {  if (isStepNum(i)) { cout << i << " "; } } }

bool isStepNum(int num)
{
    if (num < 10) { return true; }
    string numStr = to_string(num);
    for (int i = 1; i < numStr.length(); i++)
    {
        int diff = abs(numStr[i] - numStr[i - 1]);
        if (diff != 1) { return false; }
    }
    return true;
}

void findSteppingNumbers(int low, int high, int current, vector<int>& result)
{
    if (current >= low && current <= high) { if (isStepNum(current)) { result.push_back(current); } }
    if (current == 0 || current > high) { return; }
    int lastDigit = current % 10;
    if (lastDigit > 0) { findSteppingNumbers(low, high, current * 10 + lastDigit - 1, result); }
    if (lastDigit < 9) { findSteppingNumbers(low, high, current * 10 + lastDigit + 1, result); }
}

vector<int> getSteppingNumbers(int low, int high)
{
    vector<int> result;
    for (int i = 0; i <= 9; i++) { findSteppingNumbers(low, high, i, result); }
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    int low, high;
    cin >> low >> high;
    vector<int> steppingNumbers = getSteppingNumbers(low, high);
    for (int num : steppingNumbers) { cout << num << " "; }
    return 0;
}
