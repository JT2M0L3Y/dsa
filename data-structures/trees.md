# Trees

A tree is a connected, acyclic hierarchy. Binary trees have at most two children per node; a binary search tree (BST) additionally orders keys so left-subtree keys precede the node and right-subtree keys follow it.

## Operations and trade-offs

| Structure / operation | Cost |
| --- | --- |
| Binary tree traversal | O(n) |
| Search/insert in balanced BST | O(log n) |
| Search/insert in unbalanced BST | O(n) worst case |

Balanced trees such as AVL and red-black trees maintain height through rotations and balancing invariants. A plain BST does not guarantee balance. Use trees for hierarchical data, ordered queries, and recursive decomposition; use a hash table for average constant-time exact-key lookup when order is unnecessary.

## Example: in-order traversal

### Python

```python
class Node:
    def __init__(self, value: int, left=None, right=None):
        self.value, self.left, self.right = value, left, right


def inorder(node):
    if node is None:
        return []
    return inorder(node.left) + [node.value] + inorder(node.right)


root = Node(2, Node(1), Node(3))
print(inorder(root))
```

### Java

```java
import java.util.ArrayList;
import java.util.List;

class TreeExample {
    static class Node {
        int value;
        Node left, right;
        Node(int value) { this.value = value; }
    }

    static void inorder(Node node, List<Integer> result) {
        if (node == null) return;
        inorder(node.left, result);
        result.add(node.value);
        inorder(node.right, result);
    }

    public static void main(String[] args) {
        Node root = new Node(2);
        root.left = new Node(1);
        root.right = new Node(3);
        List<Integer> result = new ArrayList<>();
        inorder(root, result);
        System.out.println(result);
    }
}
```

### C++

```cpp
#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};

void inorder(Node* node, std::vector<int>& result) {
    if (node == nullptr) return;
    inorder(node->left, result);
    result.push_back(node->value);
    inorder(node->right, result);
}

int main() {
    Node left{1}, right{3}, root{2, &left, &right};
    std::vector<int> result;
    inorder(&root, result);
    for (int value : result) std::cout << value << ' ';
    std::cout << '\n';
}
```

## Related patterns

[Tree DFS](../patterns/tree-dfs/README.md), [Tree BFS](../patterns/tree-bfs/README.md), and [Topological Sort](../patterns/topological-sort/README.md).
