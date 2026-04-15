
/*
Happy Number (LC 202)
easy
🔥 High freq
Repeatedly sum digit². Detect cycle with fast/slow pointer or a set. All cycles lead to 4.
🔍 Why Google asks: Tests cycle detection (Floyd) + modular digit extraction.

Here’s a **complete interview-style explanation** of **[Happy Number problem (LeetCode 202)](https://leetcode.com/discuss/post/7263440/?utm_source=chatgpt.com)** with:

* Problem intuition
* Multiple approaches
* Algorithms
* C++ code
* Time & space complexity
* Interview tips ⭐

---

# 🔢 Happy Number — Problem Summary

A number is **happy** if repeatedly replacing it with the **sum of squares of its digits** eventually results in **1**. If the process enters a cycle that never reaches 1 → not happy. ([LeetCode][1])

Example:

```
19
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1  → Happy number
```

---

# ✅ Approach 1: Using HashSet (Most Common Solution)

## Idea

If a number repeats during transformation → cycle detected → not happy.

So store visited values in a set.

---

## Algorithm

1. Create empty set `visited`
2. While `n != 1`

   * If `n` already exists in set → return false
   * Insert `n`
   * Replace `n` with sum of squares of digits
3. Return true

---

## C++ Code

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int getNext(int n)
{
    int sum = 0;

    while(n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    unordered_set<int> visited;

    while(n != 1)
    {
        if(visited.count(n))
            return false;

        visited.insert(n);
        n = getNext(n);
    }

    return true;
}
```

---

## Complexity

Let digits = **d**

* **TC:** O(log n)
* **SC:** O(log n)

(best standard solution)

---

# ✅ Approach 2: Floyd’s Cycle Detection (Most Optimal ⭐)

Same idea as **Linked List Cycle Detection**

Uses:

* slow pointer → moves 1 step
* fast pointer → moves 2 steps

If they meet → cycle exists

---

## Algorithm

1. slow = n
2. fast = next(n)
3. While fast != 1 AND slow != fast

   * slow = next(slow)
   * fast = next(next(fast))
4. If fast == 1 → happy
5. Else → not happy

---

## C++ Code

```cpp
#include <iostream>
using namespace std;

int getNext(int n)
{
    int sum = 0;

    while(n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = getNext(n);

    while(fast != 1 && slow != fast)
    {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }

    return fast == 1;
}
```

---

## Complexity

* **TC:** O(log n)
* **SC:** O(1) ✅ Best solution

Interview preferred approach ⭐

---

# ✅ Approach 3: Using Known Cycle Property (Math Trick)

All unhappy numbers eventually enter this loop:

```
4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
```

So:

If number becomes **4**, it will never reach **1**

---

## Algorithm

1. While n != 1 AND n != 4
2. Replace n with sum of squares
3. If n == 1 → happy
4. Else → not happy

---

## C++ Code

```cpp
#include <iostream>
using namespace std;

int getNext(int n)
{
    int sum = 0;

    while(n > 0)
    {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    while(n != 1 && n != 4)
    {
        n = getNext(n);
    }

    return n == 1;
}
```

---

## Complexity

* **TC:** O(log n)
* **SC:** O(1)

Very fast practical solution 🚀

---

# 📊 Approach Comparison

| Approach              | TC       | SC       | Interview Preference |
| --------------------- | -------- | -------- | -------------------- |
| HashSet               | O(log n) | O(log n) | Good                 |
| Floyd Cycle Detection | O(log n) | O(1)     | ⭐ Best               |
| Detect cycle at 4     | O(log n) | O(1)     | Smart trick          |

---

# 🧠 Interview Insight (Important)

Why complexity is **O(log n)**?

Because number of digits in `n`:

```
digits ≈ log10(n)
```

Each iteration processes digits only.

---

# ⭐ Best Answer to Write in Interview

Use **Floyd Cycle Detection**

*/