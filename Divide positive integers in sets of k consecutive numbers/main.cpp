#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

bool checker(map<int, int> &dictionary, int k)
{
    int count = 0;
    for (const auto &pair : dictionary)
    { count += pair.second; }
    if (count % k != 0) { return false; }
    int minimum_key = dictionary.begin()->first;
    for (int i = minimum_key; i < minimum_key + k; i++)
    {
        if (dictionary.find(i) == dictionary.end()) { return false; }
        dictionary[i]--;
        if (dictionary[i] == 0) { dictionary.erase(i); }
    }
    return count == k || checker(dictionary, k);
}

bool canDivideIntoSets(vector<int> &nums, int k)
{
    map<int, int> dictionary;
    for (int num : nums)
    { dictionary[num]++; }
    return checker(dictionary, k);
}

int main()
{
    string inputLine;
    getline(cin, inputLine);
    istringstream iss(inputLine);
    vector<int> nums;
    int num;
    while (iss >> num)
    { nums.push_back(num); }
    int k;
    cin >> k;
    bool result = canDivideIntoSets(nums, k);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
