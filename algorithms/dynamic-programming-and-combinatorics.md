# Dynamic Programming and Combinatorics

Dynamic programming (DP) stores answers to overlapping subproblems. Define the state, recurrence, base cases, evaluation order, and requested output before coding. Combinatorial search often combines DP with bitmasks when the tracked set is small.

## Common interview families

| Family | Example | Typical complexity |
| --- | --- | --- |
| 1D optimization | Climbing stairs, house robber | O(n) time |
| Sequence alignment | LCS, edit distance | O(nm) time and space |
| 0/1 knapsack | Select each item at most once | O(nW) time, O(W) space |
| Unbounded knapsack | Reuse an item type | O(nW) time, O(W) space |
| LIS | Longest increasing subsequence | O(n log n) with tails |
| Bitmask DP | Subset state or visit-set state | Often O(2^n poly(n)) |
| Held–Karp TSP | Minimum tour visiting each vertex | O(n² 2^n) time, O(n 2^n) space |

Knapsack variants differ by transition order and whether an item can be reused. With a one-dimensional 0/1 knapsack array, iterate capacities downward so the current item is not reused in the same round. Iterate upward for the unbounded variant.

## Example: 0/1 knapsack

`weights[i]` and `values[i]` describe each item; each item can be selected at most once.

### Python

```python
def knapsack(weights: list[int], values: list[int], capacity: int) -> int:
    best = [0] * (capacity + 1)
    for weight, value in zip(weights, values):
        for limit in range(capacity, weight - 1, -1):
            best[limit] = max(best[limit], best[limit - weight] + value)
    return best[capacity]


print(knapsack([2, 3, 4], [4, 5, 7], 5))
```

### Java

```java
class KnapsackExample {
    static int knapsack(int[] weights, int[] values, int capacity) {
        int[] best = new int[capacity + 1];
        for (int i = 0; i < weights.length; i++) {
            for (int limit = capacity; limit >= weights[i]; limit--) {
                best[limit] = Math.max(best[limit],
                    best[limit - weights[i]] + values[i]);
            }
        }
        return best[capacity];
    }

    public static void main(String[] args) {
        System.out.println(knapsack(new int[]{2, 3, 4}, new int[]{4, 5, 7}, 5));
    }
}
```

### C++

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int knapsack(const std::vector<int>& weights, const std::vector<int>& values,
             int capacity) {
    std::vector<int> best(capacity + 1, 0);
    for (int i = 0; i < static_cast<int>(weights.size()); ++i) {
        for (int limit = capacity; limit >= weights[i]; --limit) {
            best[limit] = std::max(best[limit],
                                   best[limit - weights[i]] + values[i]);
        }
    }
    return best[capacity];
}

int main() {
    std::cout << knapsack({2, 3, 4}, {4, 5, 7}, 5) << '\n';
}
```

## Traveling salesman and bitmask DP

Held–Karp represents a subset of visited vertices by a bitmask. For small n, it reduces factorial enumeration to O(n² 2^n), but remains exponential and is not appropriate for large graphs.

```text
dp[mask][last] = minimum cost to start at 0,
                 visit exactly the vertices in mask,
                 and finish at last

initialize dp[1 << 0][0] = 0
for each mask containing vertex 0:
    for each last in mask:
        for each next not in mask with an edge last -> next:
            dp[mask | (1 << next)][next] =
                min(dp[mask | (1 << next)][next],
                    dp[mask][last] + cost[last][next])
answer = min(dp[all_vertices][last] + cost[last][0])
         over last with an edge back to 0
```

## Related patterns

[Dynamic Programming (1D)](../patterns/dynamic-programming-1d/README.md), [Dynamic Programming (2D)](../patterns/dynamic-programming-2d/README.md), [Backtracking](../patterns/backtracking/README.md), [Bit Manipulation](../patterns/bit-manipulation/README.md), and [subsets/combinations/permutations](../patterns/subsets-combinations-permutations/README.md).
