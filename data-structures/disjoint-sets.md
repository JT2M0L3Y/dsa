# Disjoint Sets (Union-Find)

Disjoint sets maintain a partition of elements into non-overlapping groups. `find` returns a representative; `union` merges groups. Path compression and union by size/rank make operations amortized O(α(n)), where α is the inverse Ackermann function.

## Trade-offs

Union-find answers connectivity under merges efficiently, but it does not support splitting a set or listing all paths between vertices. Use it for connectivity, Kruskal's minimum spanning tree, and grouping.

## Example: union by size with path compression

### Python

```python
class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a: int, b: int) -> bool:
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.size[a] < self.size[b]:
            a, b = b, a
        self.parent[b] = a
        self.size[a] += self.size[b]
        return True


sets = UnionFind(4)
sets.union(0, 1)
print(sets.find(0) == sets.find(1))
```

### Java

```java
class UnionFindExample {
    static class UnionFind {
        int[] parent, size;

        UnionFind(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        boolean union(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return false;
            }
            if (size[a] < size[b]) {
                int t = a;
                a = b;
                b = t;
            }
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
    }

    public static void main(String[] args) {
        UnionFind sets = new UnionFind(4);
        sets.union(0, 1);
        System.out.println(sets.find(0) == sets.find(1));
    }
}
```

### C++

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class UnionFind {
    std::vector<int> parent, size;
public:
    explicit UnionFind(int n) : parent(n), size(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (size[a] < size[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main() {
    UnionFind sets(4);
    sets.unite(0, 1);
    std::cout << (sets.find(0) == sets.find(1)) << '\n';
}
```

## Related patterns

[Union Find](../patterns/union-find/README.md), [Kruskal's algorithm](../algorithms/graph-algorithms.md#minimum-spanning-trees), and [graph traversal](../patterns/graph-bfs-dfs/README.md).
