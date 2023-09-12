#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// bool checker(map<int, int> &dictionary, int k)
// {
//     int count = 0;
//     for (const auto &pair : dictionary)
//     { count += pair.second; }
//     if (count % k != 0) { return false; }
//     int minimum_key = dictionary.begin()->first;
//     for (int i = minimum_key; i < minimum_key + k; i++)
//     {
//         if (dictionary.find(i) == dictionary.end()) { return false; }
//         dictionary[i]--;
//         if (dictionary[i] == 0) { dictionary.erase(i); }
//     }
//     return count == k || checker(dictionary, k);
// }

// bool canDivideIntoSets(vector<int> &nums, int k)
// {
//     map<int, int> dictionary;
//     for (int num : nums)
//     { dictionary[num]++; }
//     return checker(dictionary, k);
// }

// int main()
// {
//     string inputLine;
//     getline(cin, inputLine);
//     istringstream iss(inputLine);
//     vector<int> nums;
//     int num;
//     while (iss >> num)
//     { nums.push_back(num); }
//     int k;
//     cin >> k;
//     bool result = canDivideIntoSets(nums, k);
//     cout << (result ? "true" : "false") << endl;
//     return 0;
// }

bool canDivide(std::vector<int>& nums, int k) {
    if (nums.empty()) { return true; }
    int start = nums[0];
    vector<int> toRemove;
    for (int i = 0; i < k; i++)
    {
        auto it = find(nums.begin(), nums.end(), start + i);
        if (it == nums.end()) { return false; }
        toRemove.push_back(start + i);
    }
    for (int num : toRemove) { nums.erase(find(nums.begin(), nums.end(), num)); }
    return canDivide(nums, k);
}

int main()
{
    vector<int> nums;
    int k, val;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> val) { nums.push_back(val); }
    cin >> k;
    sort(nums.begin(), nums.end());
    if (nums.size() % k != 0)
    {
        cout << "false\n";
        return 0;
    }
    cout << (canDivide(nums, k) ? "true\n" : "false\n");
    return 0;
}
