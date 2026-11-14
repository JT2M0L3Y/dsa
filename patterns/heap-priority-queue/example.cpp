#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topKLargest(const vector<int>& nums, int k) { priority_queue<int, vector<int>, greater<int>> minHeap; for (int x : nums) { minHeap.push(x); if (minHeap.size() > (size_t)k) minHeap.pop(); } vector<int> result; while (!minHeap.empty()) { result.push_back(minHeap.top()); minHeap.pop(); } return result; }

int main() { vector<int> nums = {3,2,1,5,4}; auto result = topKLargest(nums, 3); for (int x : result) cout << x << " "; cout << endl; return 0; }
