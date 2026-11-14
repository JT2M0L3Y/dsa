#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> activitySelection(vector<pair<int, int>> intervals) { sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){ return a.second < b.second; }); vector<pair<int,int>> chosen; int lastEnd = -1; for (const auto& interval : intervals) { if (interval.first >= lastEnd) { chosen.push_back(interval); lastEnd = interval.second; } } return chosen; }

int main() { vector<pair<int, int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {5, 7}}; auto result = activitySelection(intervals); for (const auto& item : result) cout << item.first << "-" << item.second << " "; cout << endl; return 0; }
