#include <iostream>
#include <vector>
using namespace std;

int rangeSum(const vector<int>& nums, int left, int right) { 
  vector<int> prefix(nums.size() + 1, 0); 
  for (int i = 0; i < (int)nums.size(); i++)
    prefix[i + 1] = prefix[i] + nums[i]; 
  return prefix[right + 1] - prefix[left];
}

int main() { 
  vector<int> nums = {1, 2, 3, 4, 5};
  cout << rangeSum(nums, 1, 3) << endl;
  return 0;
}
