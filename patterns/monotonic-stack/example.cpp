#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(const vector<int>& nums) { vector<int> result(nums.size(), -1); stack<int> st; for (int i = (int)nums.size() - 1; i >= 0; i--) { while (!st.empty() && st.top() <= nums[i]) st.pop(); if (!st.empty()) result[i] = st.top(); st.push(nums[i]); } return result; }

int main() { vector<int> nums = {2, 1, 3, 5, 4}; auto result = nextGreater(nums); for (int x : result) cout << x << " "; cout << endl; return 0; }
