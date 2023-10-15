#include <iostream>
#include <vector>

using namespace std;

int LBS(vector<int> const &nums) {
  int n = nums.size();
  vector<int> LIS(n,1);
  vector<int> DIS(n,1);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(nums[j] < nums[i] && (1 + LIS[j]) > LIS[i]) {
        LIS[i] = 1 + LIS[j];
      }
    }
  }
  for(int i = n-1 ; i >= 0; i--) {
    for(int j = n-1; j > i; j--)  {
      if(nums[j] < nums[i] && (1 + DIS[j]) > DIS[i]) {
        DIS[i] = 1 + DIS[j];
      }
    }
  }
  int LBS = 0;
  for(int i = 0; i < n; i++) {
    LBS = max(LBS, LIS[i] + DIS[i] - 1);
  }
  
  return LBS;
  
}
int main() {
  int n;
  int input;
  cin >> n;
  vector<int> nums;
  for(int i = 0; i < n; i++) {
    cin >> input;
    nums.push_back(input);
  }
  cout << LBS(nums);
}
