# Data Structures

Data structures organize data so operations such as lookup, insertion, deletion, and traversal have useful costs. Choose a structure from the operations and constraints the problem needs; a DSA pattern describes the approach used to solve the problem, not the structure itself.

## Core interview structures

| Structure | Main strengths | Typical costs |
| --- | --- | --- |
| [Arrays and dynamic arrays](./arrays-and-dynamic-arrays.md) | Indexed access, compact sequential data | Access O(1); middle insertion/deletion O(n) |
| [Linked lists](./linked-lists.md) | Local insertion/deletion when a node is known | Search/indexing O(n) |
| [Stacks, queues, and deques](./stacks-queues-and-deques.md) | LIFO, FIFO, and double-ended processing | End operations O(1) |
| [Hash tables](./hash-tables.md) | Fast average-case key lookup | Average O(1) operations; worst O(n) |
| [Trees](./trees.md) | Hierarchy, ordered search, range organization | Balanced search O(log n); unbalanced O(n) |
| [Heaps](./heaps.md) | Repeated minimum/maximum and top-k | Peek O(1); push/pop O(log n) |
| [Graphs](./graphs.md) | General relationships and reachability | BFS/DFS O(V + E) with adjacency lists |
| [Tries](./tries.md) | Prefix-oriented string lookup | O(L) per operation for key length L |
| [Disjoint sets](./disjoint-sets.md) | Dynamic connectivity and grouping | Amortized near O(1) per operation |
| [Range-query structures](./range-query-structures.md) | Repeated range aggregation and updates | Fenwick/segment tree operations O(log n) |

## Supporting structures for system design

[Caches, bloom filters, and storage indexes](./system-design-structures.md) are covered conceptually. Their internals are useful interview vocabulary, but full storage-engine implementations are outside this guide's scope.

## Choosing a structure

Start with the operations the workload performs most often, then consider ordering, update frequency, memory, and worst-case behavior. A heap is not a sorted collection; a hash table does not preserve order; a cache is a policy layered over storage rather than a new lookup complexity guarantee.

Related material: [patterns](../patterns/related-patterns.md), [algorithms](../algorithms/README.md), and [system design](../system-design/README.md).
