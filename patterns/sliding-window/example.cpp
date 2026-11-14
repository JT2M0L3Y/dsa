#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumSubarray(const vector<int>& nums, int k) {
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += nums[i];
    int best = windowSum;
    for (int i = k; i < (int)nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        best = max(best, windowSum);
    }
    return best;
}

int main() {
    vector<int> nums = {1, 3, 2, 6, 4, 5};
    cout << maxSumSubarray(nums, 3) << endl;
    return 0;
}
