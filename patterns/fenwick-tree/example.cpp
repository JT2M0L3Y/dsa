#include <iostream>
#include <vector>
using namespace std;

class Fenwick { vector<int> bit; int n; public: Fenwick(const vector<int>& nums) : n((int)nums.size()), bit(n + 1, 0) { for (int i = 0; i < n; i++) add(i, nums[i]); } void add(int index, int delta) { index += 1; while (index <= n) { bit[index] += delta; index += index & -index; } } int prefixSum(int index) const { index += 1; int sum = 0; while (index > 0) { sum += bit[index]; index -= index & -index; } return sum; } };

int main() { Fenwick fw({1, 2, 3, 4, 5}); cout << fw.prefixSum(3) << endl; fw.add(2, 10); cout << fw.prefixSum(3) << endl; return 0; }
