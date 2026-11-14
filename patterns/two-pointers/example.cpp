#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSumTarget(const vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size() - 1;
    while (left < right) {
        int current = nums[left] + nums[right];
        if (current == target) return {left, right};
        if (current < target) left++;
        else right--;
    }
    return {};
}

int main() {
    vector<int> nums = {1, 3, 4, 7, 10, 12};
    auto result = pairSumTarget(nums, 11);
    if (!result.empty()) cout << result[0] << ", " << result[1] << endl;
    return 0;
}
