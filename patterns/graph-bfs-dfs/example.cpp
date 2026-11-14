#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int connectedComponents(int n, const vector<vector<int>>& edges) { vector<vector<int>> graph(n); for (const auto& edge : edges) { graph[edge[0]].push_back(edge[1]); graph[edge[1]].push_back(edge[0]); } vector<bool> visited(n, false); int count = 0; for (int start = 0; start < n; start++) { if (visited[start]) continue; count++; queue<int> q; q.push(start); visited[start] = true; while (!q.empty()) { int node = q.front(); q.pop(); for (int nxt : graph[node]) { if (!visited[nxt]) { visited[nxt] = true; q.push(nxt); } } } } return count; }

int main() { vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}}; cout << connectedComponents(5, edges) << endl; return 0; }
