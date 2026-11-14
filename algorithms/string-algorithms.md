# String Algorithms

String algorithms exploit character order and repeated substrings. For long inputs, replacing a naive O(nm) scan with prefix preprocessing or hashing can change the total cost substantially.

## Common choices

| Algorithm | Use | Typical time |
| --- | --- | --- |
| KMP | Exact pattern matching | O(n + m) |
| Z algorithm | Prefix matches at every position | O(n) |
| Rolling hash | Fast substring fingerprints | O(n + m), with collision risk |
| Manacher's algorithm | Longest palindromic substring | O(n) |
| Suffix array / automaton | Repeated-substring and many-query tasks | Usually O(n log n) build for suffix array |

Rolling hashes can collide; verify candidates when correctness requires exact matching. For a single short pattern, a built-in substring search may be clearer and sufficiently fast.

## Example: Knuth–Morris–Pratt (KMP)

The prefix table stores the longest proper prefix that is also a suffix for each pattern prefix. KMP uses it to avoid rechecking text characters.

### Python

```python
def find_all(text: str, pattern: str) -> list[int]:
    if not pattern:
        return list(range(len(text) + 1))
    prefix = [0] * len(pattern)
    j = 0
    for i in range(1, len(pattern)):
        while j and pattern[i] != pattern[j]:
            j = prefix[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
        prefix[i] = j
    matches = []
    j = 0
    for i, char in enumerate(text):
        while j and char != pattern[j]:
            j = prefix[j - 1]
        if char == pattern[j]:
            j += 1
        if j == len(pattern):
            matches.append(i - j + 1)
            j = prefix[j - 1]
    return matches


print(find_all("ababa", "aba"))
```

### Java

```java
import java.util.ArrayList;
import java.util.List;

class KmpExample {
    static List<Integer> findAll(String text, String pattern) {
        List<Integer> matches = new ArrayList<>();
        if (pattern.isEmpty()) {
            for (int i = 0; i <= text.length(); i++) {
                matches.add(i);
            }
            return matches;
        }
        int[] prefix = new int[pattern.length()];
        for (int i = 1, j = 0; i < pattern.length(); i++) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j)) {
                j = prefix[j - 1];
            }
            if (pattern.charAt(i) == pattern.charAt(j)) {
                j++;
            }
            prefix[i] = j;
        }
        for (int i = 0, j = 0; i < text.length(); i++) {
            while (j > 0 && text.charAt(i) != pattern.charAt(j)) {
                j = prefix[j - 1];
            }
            if (text.charAt(i) == pattern.charAt(j)) {
                j++;
            }
            if (j == pattern.length()) {
                matches.add(i - j + 1);
                j = prefix[j - 1];
            }
        }
        return matches;
    }

    public static void main(String[] args) {
        System.out.println(findAll("ababa", "aba"));
    }
}
```

### C++

```cpp
#include <iostream>
#include <string>
#include <vector>

std::vector<int> find_all(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    if (pattern.empty()) {
        for (int i = 0; i <= static_cast<int>(text.size()); ++i) {
            matches.push_back(i);
        }
        return matches;
    }
    std::vector<int> prefix(pattern.size());
    for (int i = 1, j = 0; i < static_cast<int>(pattern.size()); ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        prefix[i] = j;
    }
    for (int i = 0, j = 0; i < static_cast<int>(text.size()); ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == static_cast<int>(pattern.size())) {
            matches.push_back(i - j + 1);
            j = prefix[j - 1];
        }
    }
    return matches;
}

int main() {
    for (int index : find_all("ababa", "aba")) {
        std::cout << index << ' ';
    }
    std::cout << '\n';
}
```

## Related patterns and structures

[Trie](../data-structures/tries.md), [Hashing / HashMap Patterns](../patterns/hashing-hashmap/README.md), and [two pointers](../patterns/two-pointers/README.md).
