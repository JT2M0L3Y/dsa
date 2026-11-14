#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int> nums) {
    int i = 0;
    while (i < (int)nums.size()) {
        int correct = nums[i];
        if (nums[i] < (int)nums.size() && nums[i] != nums[correct]) swap(nums[i], nums[correct]);
        else i++;
    }
    for (int idx = 0; idx < (int)nums.size(); idx++) if (nums[idx] != idx) return idx;
    return (int)nums.size();
}

int main() {
    vector<int> nums = {0, 1, 3, 4};
    cout << findMissingNumber(nums) << endl;
    return 0;
}
