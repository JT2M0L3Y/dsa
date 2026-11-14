#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

using Graph = unordered_map<char, vector<pair<char, int>>>;

unordered_map<char, int> dijkstra(const Graph& graph, char start) { unordered_map<char, int> dist; for (const auto& [node, _] : graph) dist[node] = INT_MAX; dist[start] = 0; priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq; pq.push({0, start}); while (!pq.empty()) { auto [cost, node] = pq.top(); pq.pop(); if (cost > dist[node]) continue; for (const auto& [nxt, weight] : graph.at(node)) { int newCost = cost + weight; if (newCost < dist[nxt]) { dist[nxt] = newCost; pq.push({newCost, nxt}); } } } return dist; }

int main() { Graph graph = {{'A', {{'B', 2}, {'C', 5}}}, {'B', {{'C', 1}, {'D', 4}}}, {'C', {{'D', 1}}}, {'D', {}}}; auto dist = dijkstra(graph, 'A'); for (const auto& [node, cost] : dist) cout << node << ": " << cost << endl; return 0; }
