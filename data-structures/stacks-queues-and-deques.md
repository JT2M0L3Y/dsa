# Stacks, Queues, and Deques

A stack is last-in, first-out (LIFO); a queue is first-in, first-out (FIFO); a deque supports efficient insertion and removal at both ends.

## Operations and trade-offs

| Structure | Common operations | Cost |
| --- | --- | --- |
| Stack | push, pop, peek | O(1) |
| Queue | enqueue, dequeue, front | O(1) with a suitable implementation |
| Deque | push/pop at either end | O(1) |

Use a stack for nested structure, undo, and monotonic processing; a queue for level-order traversal and work scheduling; a deque for sliding windows. Avoid removing index 0 from a dynamic array when a queue operation is required.

## Example: use a stack and a queue

### Python

```python
from collections import deque

stack = []
stack.append("first")
stack.append("second")
print(stack.pop())

queue = deque(["first", "second"])
queue.append("third")
print(queue.popleft())
```

### Java

```java
import java.util.ArrayDeque;
import java.util.Deque;

class StackQueueExample {
    public static void main(String[] args) {
        Deque<String> stack = new ArrayDeque<>();
        stack.push("first");
        stack.push("second");
        System.out.println(stack.pop());

        Deque<String> queue = new ArrayDeque<>();
        queue.addLast("first");
        queue.addLast("second");
        queue.addLast("third");
        System.out.println(queue.removeFirst());
    }
}
```

### C++

```cpp
#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    std::cout << stack.top() << ' ';
    stack.pop();

    std::queue<int> queue;
    queue.push(1);
    queue.push(2);
    std::cout << queue.front() << '\n';
}
```

## Related patterns

[Stack / Queue Patterns](../patterns/stack-queue/README.md), [monotonic stack](../patterns/monotonic-stack/README.md), and [tree BFS](../patterns/tree-bfs/README.md).
