#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<int>& nums, int start, vector<int> path, int remaining, vector<vector<int>>& result) { if (remaining == 0) { result.push_back(path); return; } for (int i = start; i < (int)nums.size(); i++) { if (nums[i] > remaining) break; path.push_back(nums[i]); dfs(nums, i + 1, path, remaining - nums[i], result); path.pop_back(); } }

int main() { vector<int> nums = {1, 2, 3, 4}; vector<vector<int>> result; dfs(nums, 0, {}, 5, result); for (const auto& subset : result) { for (int x : subset) cout << x << " "; cout << endl; } return 0; }
