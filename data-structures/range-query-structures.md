# Range-Query Structures

Range-query structures support repeated aggregate queries over intervals, often alongside updates.

## Fenwick tree and segment tree

| Structure | Typical supported operations | Costs | Best fit |
| --- | --- | --- | --- |
| Fenwick tree (BIT) | Point update, prefix sum; range sum from two prefixes | O(log n) | Compact additive aggregates |
| Segment tree | Range aggregate and point update; can extend to range updates | O(log n) | Flexible associative operations |

Both use O(n) space. A prefix-sum array gives O(1) static range sums but costs O(n) to update one value. A segment tree supports richer operations and lazy propagation at greater implementation complexity. Fenwick trees are simpler but do not directly support every operation (for example, arbitrary range minimum with updates).

The runnable implementations are already part of the pattern guide: [Fenwick tree](../patterns/fenwick-tree/README.md) and [segment tree](../patterns/segment-tree/README.md).

## Choosing between them

- Static data with range sums: prefix sums.
- Point updates and prefix/range sums: Fenwick tree.
- Range minimum/maximum, custom associative aggregates, or lazy range updates: segment tree.

Related: [Prefix Sum](../patterns/prefix-sum/README.md), [Fenwick Tree](../patterns/fenwick-tree/README.md), and [Segment Tree](../patterns/segment-tree/README.md).
