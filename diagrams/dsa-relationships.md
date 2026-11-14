# Data Structures, Patterns, and Algorithms

Node labels identify the kind of concept: **DS** (data structure), **Pattern** (reusable problem-solving approach), or **Algorithm** (a concrete procedure). Relationship labels distinguish “uses” from “implements” and “commonly combines with”; these are common associations, not requirements.

## Overview

```mermaid
flowchart LR
    subgraph DS[Data structures]
        Array[DS: Array]
        Hash[DS: Hash map]
        Heap[DS: Heap]
        Graph[DS: Graph]
        UnionFind[DS: Union-find]
        Trie[DS: Trie]
        Fenwick[DS: Fenwick tree]
        Segment[DS: Segment tree]
    end
    subgraph Patterns[Problem-solving patterns]
        Window[Pattern: Sliding window]
        Prefix[Pattern: Prefix sum]
        PrefixSearch[Pattern: Prefix search]
        BitManipulation[Pattern: Bit manipulation]
        BFS[Pattern: Graph BFS / DFS]
        Greedy[Pattern: Greedy]
        DP[Pattern: Dynamic programming]
        Binary[Pattern: Binary search]
    end
    subgraph Algorithms[Algorithms]
        Dijkstra[Algorithm: Dijkstra]
        Kruskal[Algorithm: Kruskal]
        KMP[Algorithm: KMP]
        Knapsack[Algorithm: 0/1 knapsack]
        TSP[Algorithm: Held-Karp TSP]
    end

    Array -->|supports| Window
    Array -->|supports| Prefix
    Hash -->|commonly combines with| Window
    Hash -->|commonly combines with| Prefix
    Heap -->|commonly combines with| Greedy
    Graph -->|supports| BFS
    Graph -->|input to| Dijkstra
    Graph -->|input to| Kruskal
    UnionFind -->|implements connectivity checks in| Kruskal
    Trie -->|supports| PrefixSearch
    Array -->|stores prefix-function values for| KMP
    Fenwick -->|implements| Prefix
    Segment -->|implements range aggregates for| DP
    Binary -->|commonly combines with| Array
    DP -->|frames| Knapsack
    DP -->|frames| TSP
    BitManipulation -->|encodes subset states for| TSP
    Heap -->|supports frontier selection in| Dijkstra
    Window -->|commonly combines with| Hash
```

## Focus: range queries

```mermaid
flowchart LR
    Array[DS: Array] -->|preprocesses into| PrefixArray[Algorithm: Prefix-sum array]
    Array -->|indexed by| Fenwick[DS: Fenwick tree]
    Array -->|indexed by| Segment[DS: Segment tree]
    PrefixArray -->|answers static range sums for| PrefixPattern[Pattern: Prefix sum]
    Fenwick -->|supports updates for| PrefixPattern
    Segment -->|supports flexible aggregates for| RangePattern[Pattern: Range query]
```

Choose a prefix array for static data, a Fenwick tree for point updates and prefix aggregates, or a segment tree for more flexible associative operations.

## Focus: graph optimization

```mermaid
flowchart LR
    Graph[DS: Weighted graph] -->|input to| Dijkstra[Algorithm: Dijkstra]
    Heap[DS: Min-heap] -->|selects next state in| Dijkstra
    Graph -->|input to| Kruskal[Algorithm: Kruskal]
    UnionFind[DS: Union-find] -->|rejects cycles in| Kruskal
    Dijkstra -->|solves| ShortestPath[Pattern: Shortest path]
    Kruskal -->|solves| MST[Pattern: Minimum spanning tree]
    BFS[Algorithm: BFS] -->|solves unweighted| ShortestPath
```

The graph's weight assumptions determine the correct algorithm: BFS for unweighted edges, Dijkstra for non-negative weights, and Bellman–Ford when negative edges must be supported.

## Focus: combinatorial optimization

```mermaid
flowchart LR
    Items[DS: Array of items] -->|provides choices to| Knapsack[Algorithm: 0/1 knapsack]
    Knapsack -->|uses| DP[Pattern: Dynamic programming]
    Graph[DS: Weighted graph] -->|provides costs to| TSP[Algorithm: Held-Karp TSP]
    TSP -->|encodes visited subset as| Bitmask[Pattern: Bitmask state]
    TSP -->|uses| DP
    Choices[Pattern: Backtracking] -->|may be pruned or memoized as| DP
```

Related indexes: [data structures](../data-structures/README.md), [patterns](../patterns/related-patterns.md), and [algorithms](../algorithms/README.md).
