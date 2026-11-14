# Graph Algorithms

Graph algorithms answer reachability, ordering, connectivity, and path-cost questions. Choose by edge weights and graph structure; an algorithm's preconditions are part of its correctness.

## Common algorithms

| Problem | Algorithm | Time |
| --- | --- | --- |
| Reachability / components | BFS or DFS | O(V + E) |
| Directed acyclic ordering | Kahn's algorithm or DFS postorder | O(V + E) |
| Single-source shortest path, unweighted | BFS | O(V + E) |
| Single-source shortest path, non-negative weights | Dijkstra with a heap | O((V + E) log V) |
| Negative edge weights | Bellman–Ford | O(VE) |
| All-pairs shortest paths | Floyd–Warshall | O(V³) |
| Minimum spanning tree | Kruskal or Prim | O(E log E) / O(E log V) |

Dijkstra is not valid with negative edge weights. A topological order exists only for a DAG. A minimum spanning tree connects all vertices of an undirected connected weighted graph; it is not a shortest-path tree.

## Example: Dijkstra with non-negative weights

The graph is an adjacency list of `(neighbor, weight)` pairs. Distances left at infinity are unreachable.

### Python

```python
import heapq
import math

def dijkstra(graph: list[list[tuple[int, int]]], source: int) -> list[float]:
    distance = [math.inf] * len(graph)
    distance[source] = 0
    frontier = [(0, source)]
    while frontier:
        cost, node = heapq.heappop(frontier)
        if cost != distance[node]:
            continue
        for neighbor, weight in graph[node]:
            candidate = cost + weight
            if candidate < distance[neighbor]:
                distance[neighbor] = candidate
                heapq.heappush(frontier, (candidate, neighbor))
    return distance


print(dijkstra([[(1, 4), (2, 1)], [(3, 1)], [(1, 2), (3, 5)], []], 0))
```

### Java

```java
import java.util.*;

class DijkstraExample {
    static long[] dijkstra(List<List<int[]>> graph, int source) {
        long[] distance = new long[graph.size()];
        Arrays.fill(distance, Long.MAX_VALUE);
        distance[source] = 0;
        PriorityQueue<long[]> frontier = new PriorityQueue<>(
            Comparator.comparingLong((long[] state) -> state[0]));
        frontier.add(new long[]{0, source});
        while (!frontier.isEmpty()) {
            long[] current = frontier.remove();
            long cost = current[0];
            int node = (int) current[1];
            if (cost != distance[node]) continue;
            for (int[] edge : graph.get(node)) {
                int neighbor = edge[0], weight = edge[1];
                long candidate = cost + weight;
                if (candidate < distance[neighbor]) {
                    distance[neighbor] = candidate;
                    frontier.add(new long[]{candidate, neighbor});
                }
            }
        }
        return distance;
    }

    public static void main(String[] args) {
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i < 4; i++) graph.add(new ArrayList<>());
        graph.get(0).add(new int[]{1, 4}); graph.get(0).add(new int[]{2, 1});
        graph.get(1).add(new int[]{3, 1});
        graph.get(2).add(new int[]{1, 2}); graph.get(2).add(new int[]{3, 5});
        System.out.println(Arrays.toString(dijkstra(graph, 0)));
    }
}
```

### C++

```cpp
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

std::vector<long long> dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph,
                                int source) {
    const long long inf = std::numeric_limits<long long>::max();
    std::vector<long long> distance(graph.size(), inf);
    using State = std::pair<long long, int>;
    std::priority_queue<State, std::vector<State>, std::greater<State>> frontier;
    distance[source] = 0;
    frontier.push({0, source});
    while (!frontier.empty()) {
        auto [cost, node] = frontier.top();
        frontier.pop();
        if (cost != distance[node]) continue;
        for (auto [neighbor, weight] : graph[node]) {
            long long candidate = cost + weight;
            if (candidate < distance[neighbor]) {
                distance[neighbor] = candidate;
                frontier.push({candidate, neighbor});
            }
        }
    }
    return distance;
}

int main() {
    std::vector<std::vector<std::pair<int, int>>> graph(4);
    graph[0] = {{1, 4}, {2, 1}};
    graph[1] = {{3, 1}};
    graph[2] = {{1, 2}, {3, 5}};
    for (long long value : dijkstra(graph, 0)) std::cout << value << ' ';
    std::cout << '\n';
}
```

## Minimum spanning trees

Kruskal sorts edges by weight and accepts an edge when it joins two previously disconnected components; union-find supports the connectivity check. Prim grows one tree by repeatedly choosing the cheapest edge leaving the current tree. Both are greedy, but neither solves a shortest-path problem.

## Related patterns and structures

[Graph BFS / DFS](../patterns/graph-bfs-dfs/README.md), [Topological Sort](../patterns/topological-sort/README.md), [Shortest Path Algorithms](../patterns/shortest-path/README.md), [Union Find](../data-structures/disjoint-sets.md), and [heaps](../data-structures/heaps.md).
