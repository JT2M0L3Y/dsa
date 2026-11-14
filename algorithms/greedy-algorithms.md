# Greedy Algorithms

A greedy algorithm makes a locally optimal choice and commits to it. Greedy is correct only when the problem has a proof supporting that choice; a plausible heuristic is not enough.

## Common examples

- **Interval scheduling:** sort by finish time and repeatedly take the compatible interval; this maximizes the number of non-overlapping intervals.
- **Minimum spanning tree:** Kruskal and Prim repeatedly choose a safe minimum-weight edge.
- **Huffman coding:** repeatedly combine the two least frequent symbols to build an optimal prefix code.
- **Fractional knapsack:** take value per unit weight in descending order; this does not solve 0/1 knapsack.

## Example: maximum number of non-overlapping intervals

Intervals are half-open `[start, end)`. Sorting by end time enables the exchange argument: any optimal solution's first interval can be replaced by the one that finishes earliest without reducing the remaining choices.

### Python

```python
def select_intervals(intervals: list[tuple[int, int]]) -> list[tuple[int, int]]:
    chosen = []
    for start, end in sorted(intervals, key=lambda interval: interval[1]):
        if not chosen or start >= chosen[-1][1]:
            chosen.append((start, end))
    return chosen


print(select_intervals([(1, 3), (2, 4), (3, 5), (5, 7)]))
```

### Java

```java
import java.util.*;

class IntervalSchedulingExample {
    static List<int[]> select(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[1]));
        List<int[]> chosen = new ArrayList<>();
        for (int[] interval : intervals) {
            if (chosen.isEmpty() || interval[0] >= chosen.get(chosen.size() - 1)[1]) {
                chosen.add(interval);
            }
        }
        return chosen;
    }

    public static void main(String[] args) {
        int[][] intervals = {{1, 3}, {2, 4}, {3, 5}, {5, 7}};
        System.out.println(select(intervals).size());
    }
}
```

### C++

```cpp
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> select_intervals(
    std::vector<std::pair<int, int>> intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const auto& a, const auto& b) {
                  return a.second < b.second;
              });
    std::vector<std::pair<int, int>> chosen;
    for (auto interval : intervals) {
        if (chosen.empty() || interval.first >= chosen.back().second) {
            chosen.push_back(interval);
        }
    }
    return chosen;
}

int main() {
    auto chosen = select_intervals({{1, 3}, {2, 4}, {3, 5}, {5, 7}});
    std::cout << chosen.size() << '\n';
}
```

## Related patterns

[Merge Intervals](../patterns/merge-intervals/README.md), [Greedy Algorithms](../patterns/greedy-algorithms/README.md), and [heaps](../data-structures/heaps.md).
