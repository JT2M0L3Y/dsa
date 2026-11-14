# Graphs

A graph consists of vertices and edges. Edges may be directed or undirected, weighted or unweighted. An adjacency list stores each vertex's neighbors and uses O(V + E) space.

## Representations and costs

| Representation | Space | Check whether edge exists |
| --- | --- | --- |
| Adjacency list | O(V + E) | O(degree(v)) |
| Adjacency matrix | O(V²) | O(1) |

Adjacency lists suit sparse graphs and neighborhood traversal. Matrices suit dense graphs or frequent edge-existence checks. BFS/DFS over an adjacency list runs in O(V + E).

## Example: breadth-first traversal

### Python

```python
from collections import deque

graph = {0: [1, 2], 1: [0, 3], 2: [0], 3: [1]}
queue = deque([0])
seen = {0}
order = []
while queue:
    node = queue.popleft()
    order.append(node)
    for neighbor in graph[node]:
        if neighbor not in seen:
            seen.add(neighbor)
            queue.append(neighbor)
print(order)
```

### Java

```java
import java.util.*;

class GraphExample {
    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        graph.add(Arrays.asList(1, 2));
        graph.add(Arrays.asList(0, 3));
        graph.add(Arrays.asList(0));
        graph.add(Arrays.asList(1));
        Queue<Integer> queue = new ArrayDeque<>();
        boolean[] seen = new boolean[graph.size()];
        queue.add(0);
        seen[0] = true;
        while (!queue.isEmpty()) {
            int node = queue.remove();
            System.out.print(node + " ");
            for (int neighbor : graph.get(node)) {
                if (!seen[neighbor]) {
                    seen[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
        System.out.println();
    }
}
```

### C++

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::vector<std::vector<int>> graph{{1, 2}, {0, 3}, {0}, {1}};
    std::queue<int> queue;
    std::vector<bool> seen(graph.size(), false);
    queue.push(0);
    seen[0] = true;
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        std::cout << node << ' ';
        for (int neighbor : graph[node]) {
            if (!seen[neighbor]) {
                seen[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
    std::cout << '\n';
}
```

## Related patterns

[Graph BFS / DFS](../patterns/graph-bfs-dfs/README.md), [Topological Sort](../patterns/topological-sort/README.md), and [Union Find](../patterns/union-find/README.md).
