#include <iostream>
#include <vector>
using namespace std;

void dfs(const vector<int>& nums, int start, vector<int> path, vector<vector<int>>& result) { result.push_back(path); for (int i = start; i < (int)nums.size(); i++) { path.push_back(nums[i]); dfs(nums, i + 1, path, result); path.pop_back(); } }

int main() { vector<int> nums = {1,2,3}; vector<vector<int>> result; dfs(nums, 0, {}, result); for (const auto& subset : result) { for (int x : subset) cout << x << " "; cout << endl; } return 0; }
