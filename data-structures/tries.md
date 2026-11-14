# Tries (Prefix Trees)

A trie stores keys by shared prefixes. Each edge represents a character; a terminal marker distinguishes a complete key from a prefix.

## Operations and trade-offs

For a key of length L, lookup, insertion, and prefix checks take O(L). Space depends on the number of distinct prefixes and child representation. A trie can use more memory than a hash table but supports prefix queries directly.

Use a trie for autocomplete, dictionary prefix queries, and character-by-character search. For exact-key membership alone, a hash set is usually simpler.

## Example: insert and search lowercase words

### Python

```python
class TrieNode:
    def __init__(self):
        self.children = {}
        self.terminal = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for char in word:
            node = node.children.setdefault(char, TrieNode())
        node.terminal = True

    def search(self, word: str) -> bool:
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.terminal


trie = Trie()
trie.insert("tree")
print(trie.search("tree"), trie.search("tre"))
```

### Java

```java
class TrieExample {
    static class Node {
        Node[] children = new Node[26];
        boolean terminal;
    }

    static class Trie {
        Node root = new Node();
        void insert(String word) {
            Node node = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null) node.children[index] = new Node();
                node = node.children[index];
            }
            node.terminal = true;
        }
        boolean search(String word) {
            Node node = root;
            for (char c : word.toCharArray()) {
                node = node.children[c - 'a'];
                if (node == null) return false;
            }
            return node.terminal;
        }
    }

    public static void main(String[] args) {
        Trie trie = new Trie();
        trie.insert("tree");
        System.out.println(trie.search("tree") + " " + trie.search("tre"));
    }
}
```

### C++

```cpp
#include <array>
#include <iostream>
#include <memory>
#include <string>

struct Node {
    std::array<std::unique_ptr<Node>, 26> children{};
    bool terminal = false;
};

class Trie {
    Node root;
public:
    void insert(const std::string& word) {
        Node* node = &root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) node->children[index] = std::make_unique<Node>();
            node = node->children[index].get();
        }
        node->terminal = true;
    }
    bool search(const std::string& word) const {
        const Node* node = &root;
        for (char c : word) {
            node = node->children[c - 'a'].get();
            if (node == nullptr) return false;
        }
        return node->terminal;
    }
};

int main() {
    Trie trie;
    trie.insert("tree");
    std::cout << trie.search("tree") << ' ' << trie.search("tre") << '\n';
}
```

The Java and C++ examples assume lowercase English letters; a map of character to child is more flexible for a larger alphabet.

## Related patterns

[Trie (Prefix Tree)](../patterns/trie/README.md), [Backtracking](../patterns/backtracking/README.md), and [Hashing / HashMap Patterns](../patterns/hashing-hashmap/README.md).
