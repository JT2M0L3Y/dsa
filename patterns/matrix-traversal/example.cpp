#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countIslands(vector<string> grid) { int rows = (int)grid.size(), cols = (int)grid[0].size(); vector<vector<bool>> visited(rows, vector<bool>(cols, false)); int count = 0; vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}; for (int r = 0; r < rows; r++) { for (int c = 0; c < cols; c++) { if (grid[r][c] == '1' && !visited[r][c]) { count++; queue<pair<int,int>> q; q.push({r, c}); visited[r][c] = true; while (!q.empty()) { auto cur = q.front(); q.pop(); for (const auto& d : dirs) { int nr = cur.first + d.first, nc = cur.second + d.second; if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && !visited[nr][nc]) { visited[nr][nc] = true; q.push({nr, nc}); } } } } } } return count; }

int main() { vector<string> grid = {"11000", "11000", "00100", "00011"}; cout << countIslands(grid) << endl; return 0; }
