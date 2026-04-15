/*
Water and Jug Problem (LC 365)
medium
🔥 High freq
Possible iff target is a multiple of gcd(x,y) and ≤ x+y. Bezout's identity.
🔍 Why Google asks: Google loves this — tests if you recognise the GCD insight over brute-force BFS.


The **Water and Jug Problem** is a classic **number theory + simulation** problem. The optimal solution uses **GCD (Bézout’s identity)** and runs in **O(log min(x,y))** time.

I’ll explain **all approaches (Brute force → BFS → Mathematical)** with:

* intuition
* algorithm
* C++ code
* TC / SC
* interview tips ⭐

---

# 🔷 Problem Summary

You are given:

* jug1 capacity = `x`
* jug2 capacity = `y`
* target = `z`

Allowed operations:

1. Fill a jug
2. Empty a jug
3. Pour water from one jug to another until full/empty ([Medium][1])

Return **true** if you can measure exactly `z` liters.

---

# ✅ Approach 1: Mathematical (Best Solution ⭐)

## Key Observation

You can measure `z` **iff**

[
z \le x + y \quad \text{and} \quad z \bmod \gcd(x,y) = 0
]

This follows from **Bézout’s identity**, meaning reachable water amounts are multiples of `gcd(x,y)` ([Design Gurus][2]).

---

## Algorithm

1. If `z == 0` → return true
2. If `z > x + y` → return false
3. Compute `g = gcd(x,y)`
4. If `z % g == 0` → return true
5. Else false

---

## C++ Code

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

bool canMeasureWater(int x, int y, int z)
{
    if(z == 0)
        return true;

    if(x + y < z)
        return false;

    return (z % __gcd(x, y) == 0);
}
```

---

## Complexity

* **TC:** O(log(min(x,y)))
* **SC:** O(1)

✅ Interview best solution

---

# ✅ Approach 2: BFS (State Simulation)

Treat this as a **graph problem**.

Each state = `(jug1, jug2)`

Example:

```
(0,0) → (x,0) → (x,y) → ...
```

Traverse all possible states until reaching `z`.

---

## Algorithm

1. Use queue for BFS
2. Track visited states `(a,b)`
3. Try all operations:

   * fill jug1
   * fill jug2
   * empty jug1
   * empty jug2
   * pour jug1 → jug2
   * pour jug2 → jug1
4. If any state has:

   ```
   a == z OR b == z OR a + b == z
   ```

   return true

---

## C++ Code

```cpp
#include <iostream>
#include <queue>
#include <set>
using namespace std;

bool canMeasureWater(int x, int y, int z)
{
    if(z > x + y)
        return false;

    queue<pair<int,int>> q;
    set<pair<int,int>> visited;

    q.push({0,0});

    while(!q.empty())
    {
        auto [a,b] = q.front();
        q.pop();

        if(a == z || b == z || a + b == z)
            return true;

        if(visited.count({a,b}))
            continue;

        visited.insert({a,b});

        q.push({x,b});
        q.push({a,y});
        q.push({0,b});
        q.push({a,0});

        int pour = min(a, y-b);
        q.push({a-pour, b+pour});

        pour = min(b, x-a);
        q.push({a+pour, b-pour});
    }

    return false;
}
```

---

## Complexity

* **TC:** O(x × y)
* **SC:** O(x × y)

Useful for understanding transitions

---

# ✅ Approach 3: DFS (Recursive Simulation)

Same logic as BFS but depth-first traversal.

Rarely preferred in interviews (risk of stack overflow).

---

## Complexity

* **TC:** O(x × y)
* **SC:** O(x × y)

---

# ✅ Approach 4: Brute Force Simulation (Conceptual Only)

Try all pouring sequences manually.

Example:

```
x=3, y=5, z=4

Fill 5
→ pour into 3
→ remaining 2
→ empty 3
→ transfer 2
→ fill 5
→ pour 1
→ get 4
```

Works but not scalable.

---

# ⭐ Interview Trick (Most Important Insight)

Always check:

```
z <= x + y
AND
z % gcd(x,y) == 0
```

Example:

```
x=3
y=5
z=4

gcd(3,5)=1
4 % 1 = 0
→ possible
```

Example:

```
x=2
y=6
z=5

gcd(2,6)=2
5 % 2 ≠ 0
→ impossible
```

---

# 📊 Approach Comparison

| Approach         | TC       | SC    | Interview Value |
| ---------------- | -------- | ----- | --------------- |
| Brute simulation | Large    | Large | ❌               |
| BFS              | O(xy)    | O(xy) | Medium          |
| DFS              | O(xy)    | O(xy) | Medium          |
| Math (GCD)       | O(log n) | O(1)  | ⭐ Best          |

---

If you'd like, I can **prove why the GCD condition works mathematically** (very useful for interviews and number theory intuition).

[1]: https://dreamume.medium.com/leetcode-365-water-and-jug-problem-69735194a596?utm_source=chatgpt.com "Leetcode 365: Water and Jug Problem | by dume0011 - Medium"
[2]: https://www.designgurus.io/answers/detail/mastering-leetcodes-water-and-jug-problem-mathematical-bfs-and-dfs-solutions?utm_source=chatgpt.com "Mastering LeetCode's Water and Jug Problem"


*/