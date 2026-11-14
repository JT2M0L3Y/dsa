# Hash Tables

A hash table maps keys to values by hashing each key into a bucket. Hash maps store key-value pairs; hash sets store unique keys.

## Operations and trade-offs

| Operation | Average | Worst case |
| --- | --- | --- |
| Lookup, insert, delete | O(1) | O(n) |

Performance depends on the hash function, collision handling, and resizing. Hash tables do not inherently maintain sorted order. Use them for membership, frequency counts, and memoization; choose an ordered map when range queries or sorted iteration are required.

## Example: count frequencies

### Python

```python
from collections import Counter

counts = Counter(["pear", "plum", "pear"])
print(counts["pear"], "plum" in counts)
```

### Java

```java
import java.util.HashMap;
import java.util.Map;

class HashTableExample {
    public static void main(String[] args) {
        Map<String, Integer> counts = new HashMap<>();
        for (String value : new String[]{"pear", "plum", "pear"}) {
            counts.put(value, counts.getOrDefault(value, 0) + 1);
        }
        System.out.println(counts.get("pear") + " " + counts.containsKey("plum"));
    }
}
```

### C++

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> counts;
    for (const std::string value : {"pear", "plum", "pear"}) {
        ++counts[value];
    }
    std::cout << counts["pear"] << ' ' << (counts.find("plum") != counts.end()) << '\n';
}
```

## Related patterns

[Hashing / HashMap Patterns](../patterns/hashing-hashmap/README.md), [prefix sum](../patterns/prefix-sum/README.md), and [sliding window](../patterns/sliding-window/README.md).
