# Linked Lists

A linked list stores values in nodes connected by references. Singly linked lists use one next reference; doubly linked lists also point backward.

## Operations and trade-offs

| Operation | Cost |
| --- | --- |
| Insert/delete at head | O(1) |
| Insert/delete after a known node | O(1) |
| Search or access by index | O(n) |
| Traverse | O(n) |

Use a linked list when local edits matter and the relevant node is already known. Arrays usually provide better locality and simpler indexing. Deleting a node in a singly linked list still requires its predecessor.

## Example: reverse a singly linked list

### Python

```python
class Node:
    def __init__(self, value: int, next_node: "Node | None" = None):
        self.value = value
        self.next = next_node


def reverse(head: Node | None) -> Node | None:
    previous = None
    current = head
    while current is not None:
        following = current.next
        current.next = previous
        previous, current = current, following
    return previous


head = Node(1, Node(2, Node(3)))
reversed_head = reverse(head)
print(reversed_head.value, reversed_head.next.value)
```

### Java

```java
class LinkedListExample {
    static class Node {
        int value;
        Node next;

        Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    static Node reverse(Node head) {
        Node previous = null;
        Node current = head;
        while (current != null) {
            Node following = current.next;
            current.next = previous;
            previous = current;
            current = following;
        }
        return previous;
    }

    public static void main(String[] args) {
        Node result = reverse(new Node(1, new Node(2, new Node(3, null))));
        System.out.println(result.value + " " + result.next.value);
    }
}
```

### C++

```cpp
#include <iostream>

struct Node {
    int value;
    Node* next;
};

Node* reverse(Node* head) {
    Node* previous = nullptr;
    while (head != nullptr) {
        Node* following = head->next;
        head->next = previous;
        previous = head;
        head = following;
    }
    return previous;
}

int main() {
    Node third{3, nullptr};
    Node second{2, &third};
    Node first{1, &second};
    Node* result = reverse(&first);
    std::cout << result->value << ' ' << result->next->value << '\n';
}
```

## Related patterns

See [in-place linked-list reversal](../patterns/linked-list-reversal/README.md) and [fast and slow pointers](../patterns/fast-slow-pointers/README.md).
