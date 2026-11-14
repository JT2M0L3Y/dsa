# Heaps

A binary heap is a complete binary tree stored compactly in an array. A min-heap exposes the smallest item; a max-heap exposes the largest.

## Operations and trade-offs

| Operation | Cost |
| --- | --- |
| Peek at root | O(1) |
| Insert / remove root | O(log n) |
| Build heap from n values | O(n) |
| Find all items in sorted order | O(n log n) |

A heap is not fully sorted: only the root is guaranteed to be the minimum or maximum. Use a heap for repeated best-next selection, streaming top-k, and scheduling; use sorting when all elements need ordered traversal.

## Example: keep the three smallest values

### Python

```python
import heapq

values = [8, 2, 5, 1, 7]
smallest = heapq.nsmallest(3, values)
print(smallest)
```

### Java

```java
import java.util.Collections;
import java.util.PriorityQueue;

class HeapExample {
    public static void main(String[] args) {
        PriorityQueue<Integer> largest = new PriorityQueue<>(Collections.reverseOrder());
        for (int value : new int[]{8, 2, 5, 1, 7}) {
            largest.add(value);
            if (largest.size() > 3) largest.remove();
        }
        while (!largest.isEmpty()) System.out.print(largest.remove() + " ");
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
    std::priority_queue<int> largest;
    for (int value : {8, 2, 5, 1, 7}) {
        largest.push(value);
        if (largest.size() > 3) largest.pop();
    }
    while (!largest.empty()) {
        std::cout << largest.top() << ' ';
        largest.pop();
    }
    std::cout << '\n';
}
```

## Related patterns

[Heap / Priority Queue](../patterns/heap-priority-queue/README.md), [Greedy Algorithms](../patterns/greedy-algorithms/README.md), and [Shortest Path Algorithms](../patterns/shortest-path/README.md).
