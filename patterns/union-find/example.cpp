#include <iostream>
#include <vector>
using namespace std;

class UnionFind { public: vector<int> parent, rank; UnionFind(int n): parent(n), rank(n, 0) { for (int i = 0; i < n; ++i) parent[i] = i; } int find(int x) { if (parent[x] != x) parent[x] = find(parent[x]); return parent[x]; } void unite(int a, int b) { int ra = find(a), rb = find(b); if (ra == rb) return; if (rank[ra] < rank[rb]) parent[ra] = rb; else if (rank[ra] > rank[rb]) parent[rb] = ra; else { parent[rb] = ra; rank[ra]++; } } };

int main() { UnionFind uf(5); uf.unite(0, 1); uf.unite(1, 2); uf.unite(3, 4); cout << uf.find(2) << endl; return 0; }
