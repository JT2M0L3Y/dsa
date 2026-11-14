#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topologicalSort(int numCourses, const vector<vector<int>>& prerequisites) { vector<vector<int>> graph(numCourses); vector<int> indegree(numCourses, 0); for (const auto& edge : prerequisites) { graph[edge[1]].push_back(edge[0]); indegree[edge[0]]++; } queue<int> q; for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) q.push(i); vector<int> order; while (!q.empty()) { int course = q.front(); q.pop(); order.push_back(course); for (int nxt : graph[course]) { indegree[nxt]--; if (indegree[nxt] == 0) q.push(nxt); } } return order; }

int main() { vector<vector<int>> prereq = {{1, 0}, {2, 0}, {3, 1}, {3, 2}}; auto order = topologicalSort(4, prereq); for (int x : order) cout << x << " "; cout << endl; return 0; }
