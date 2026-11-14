#include <iostream>
#include <vector>
using namespace std;

int firstTrue(const vector<bool>& nums) { int left = 0, right = (int)nums.size() - 1, ans = -1; while (left <= right) { int mid = left + (right - left) / 2; if (nums[mid]) { ans = mid; right = mid - 1; } else left = mid + 1; } return ans; }

int main() { vector<bool> nums = {false, false, true, true, true}; cout << firstTrue(nums) << endl; return 0; }
