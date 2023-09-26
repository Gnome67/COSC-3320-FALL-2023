#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int countRotations(vector<int>& nums, int low, int high)
{
    if (high < low) { return 0; }
    if (high == low) { return low; }
    int mid = low + (high - low) / 2;
    if (mid < high && nums[mid + 1] < nums[mid]) { return (mid + 1); }
    if (mid > low && nums[mid] < nums[mid - 1]) { return mid; }
    if (nums[high] > nums[mid]) { return countRotations(nums, low, mid - 1); }
    return countRotations(nums, mid + 1, high);
}

int search(vector<int>& nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target) { return mid; }
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid]) { high = mid - 1; }
            else { low = mid + 1; }
        } else {
            if (nums[mid] < target && target <= nums[high]) { low = mid + 1; } 
            else { high = mid - 1; }
        }
    }
    return -1;
}

int main()
{
  int num = 0, k = 0, count = 0, target = 0;
  vector<int> nums;
  string input = "";
  getline(cin, input);
  cin >> k;
  stringstream s(input);
  while(s >> num) { nums.push_back(num); }
  count = countRotations(nums, 0, nums.size()-1);
  target = search(nums, k);
  cout << count << "\n" << target;
}
