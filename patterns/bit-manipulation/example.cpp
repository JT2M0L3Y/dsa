#include <iostream>
#include <vector>
using namespace std;

int singleNumber(const vector<int>& nums) { int result = 0; for (int x : nums) result ^= x; return result; }

int main() { vector<int> nums = {2, 2, 3, 3, 5}; cout << singleNumber(nums) << endl; return 0; }
