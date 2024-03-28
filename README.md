# Ordered Map with Optimized Random Index Access Support in C++

It basically behaves like a `std::map` but support random index access, i.e. accessing the `i`-th smallest element in `O(log(N))`.

# Example

```c++
#include <iostream>
#include <string>

#include "indexed_ordered_map/indexed_ordered_map.h"

int main() {
    using K = double;
    using V = std::string;
    indexed::ordered_map<K, V> map;

    map.insert({0.123, "aaa"});
    map.insert({0.012, "bbb"});
    map.insert({0.321, "ccc"});
    map.insert({0.001, "ddd"});
    map.insert({0.775, "eee"});
    auto it = map.index(3);

    // NOTE : you can only modify value if you like (not key)
    it->second = "ewq";

    std::cout << it->first << std::endl;
    std::cout << it->second << std::endl;
}
```

outputs:
```
0.321
ewq
```


## Credit

Credited to: [Generalized order-statistic tree implementation](https://github.com/dkondor/orbtree)

We made some modifications to their codes so that it can nicely compile on MSVC.


