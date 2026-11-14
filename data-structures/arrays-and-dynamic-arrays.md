# Arrays and Dynamic Arrays

An array stores elements in indexed positions. A dynamic array grows its backing storage when capacity is exhausted, preserving fast indexed access while making append amortized O(1).

## Operations and trade-offs

| Operation | Cost |
| --- | --- |
| Read or write by index | O(1) |
| Append | Amortized O(1), occasional O(n) resize |
| Insert/delete in the middle | O(n) due to shifting |
| Search an unsorted array | O(n) |

Use arrays for contiguous scans, two-pointer techniques, sorting, and indexed dynamic programming. They are a poor fit when frequent arbitrary-position insertions dominate.

## Examples: append and indexed access

### Python

```python
values = [4, 7, 9]
values.append(12)
print(values[2], values)
```

### Java

```java
import java.util.ArrayList;

class ArrayExample {
    public static void main(String[] args) {
        ArrayList<Integer> values = new ArrayList<>();
        values.add(4);
        values.add(7);
        values.add(9);
        values.add(12);
        System.out.println(values.get(2) + " " + values);
    }
}
```

### C++

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{4, 7, 9};
    values.push_back(12);
    std::cout << values[2] << ' ' << values.size() << '\n';
}
```

## Related patterns

[Two pointers](../patterns/two-pointers/README.md), [sliding window](../patterns/sliding-window/README.md), and [prefix sum](../patterns/prefix-sum/README.md) commonly operate on arrays.
