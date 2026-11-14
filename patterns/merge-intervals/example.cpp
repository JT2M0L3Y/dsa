#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged = {intervals[0]};
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1]) merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        else merged.push_back(intervals[i]);
    }
    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto result = mergeIntervals(intervals);
    for (const auto& iv : result) cout << iv[0] << " " << iv[1] << endl;
    return 0;
}
