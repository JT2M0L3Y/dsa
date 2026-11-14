#include <iostream>
#include <vector>
using namespace std;

class SegmentTree { vector<int> tree; int n; public: SegmentTree(const vector<int>& nums) : n((int)nums.size()), tree(2 * n) { for (int i = 0; i < n; i++) tree[n + i] = nums[i]; for (int i = n - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1]; } void update(int index, int value) { int pos = n + index; tree[pos] = value; pos /= 2; while (pos > 0) { tree[pos] = tree[pos * 2] + tree[pos * 2 + 1]; pos /= 2; } } int query(int left, int right) { left += n; right += n; int result = 0; while (left <= right) { if (left % 2 == 1) result += tree[left++]; if (right % 2 == 0) result += tree[right--]; left /= 2; right /= 2; } return result; } };

int main() { SegmentTree st({1, 2, 3, 4, 5}); cout << st.query(1, 3) << endl; st.update(2, 10); cout << st.query(1, 3) << endl; return 0; }
