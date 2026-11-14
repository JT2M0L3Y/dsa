# Sorting and Searching

Sorting establishes an order; searching uses properties of the input to locate a value or boundary. Binary search requires a monotone predicate or sorted search space.

## Common choices

| Algorithm | Time | Extra space | Notes |
| --- | --- | --- | --- |
| Binary search | O(log n) | O(1) iterative | Sorted data or monotone predicate |
| Merge sort | O(n log n) | O(n) | Stable; useful for linked lists and external sorting |
| Quicksort | Average O(n log n), worst O(n²) | Average O(log n) stack | In-place variants; pivot choice matters |
| Heap sort | O(n log n) | O(1) auxiliary | In-place, not stable |
| Quickselect | Average O(n) | Usually O(1) | Finds a rank without fully sorting |

Prefer the standard library sort in production. In interviews, implement only when the algorithm itself is the point. For binary search, state whether the result is any match, first match, or insertion boundary; many off-by-one errors come from leaving this unspecified.

## Example: lower bound

Return the first index whose value is at least `target`, or the array length when none exists.

### Python

```python
def lower_bound(values: list[int], target: int) -> int:
    left, right = 0, len(values)
    while left < right:
        middle = left + (right - left) // 2
        if values[middle] < target:
            left = middle + 1
        else:
            right = middle
    return left


print(lower_bound([1, 3, 3, 8], 3), lower_bound([1, 3, 3, 8], 4))
```

### Java

```java
class LowerBoundExample {
    static int lowerBound(int[] values, int target) {
        int left = 0, right = values.length;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (values[middle] < target) left = middle + 1;
            else right = middle;
        }
        return left;
    }

    public static void main(String[] args) {
        int[] values = {1, 3, 3, 8};
        System.out.println(lowerBound(values, 3) + " " + lowerBound(values, 4));
    }
}
```

### C++

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{1, 3, 3, 8};
    auto first = std::lower_bound(values.begin(), values.end(), 3);
    auto after = std::lower_bound(values.begin(), values.end(), 4);
    std::cout << (first - values.begin()) << ' ' << (after - values.begin()) << '\n';
}
```

## Related patterns and structures

[Binary Search Variations](../patterns/binary-search/README.md), [Modified Binary Search](../patterns/modified-binary-search/README.md), and [arrays](../data-structures/arrays-and-dynamic-arrays.md).
