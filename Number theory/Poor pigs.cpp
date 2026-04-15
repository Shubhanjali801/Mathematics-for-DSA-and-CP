/*
Poor Pigs (LC 458)
hard
🔥 High freq
Each pig has (t/minutesToTest+1) states. With p pigs: states^p ≥ buckets. Answer = ⌈log(buckets) / log(states)⌉.
🔍 Why Google asks: Information theory meets combinatorics. Classic Google hard — O(1) math solution.


The **Poor Pigs (LeetCode 458)** problem is a classic **math + combinatorics + logarithm** interview question. The key insight is understanding how many **states** each pig can represent across testing rounds.

I’ll explain:

* intuition (core idea)
* mathematical formula
* algorithm
* C++ code
* time & space complexity
* step-by-step example (important for interviews ⭐)

---

# 🔷 Problem Summary

You are given:

* `buckets`
* `minutesToDie`
* `minutesToTest`

Exactly **one bucket is poisonous**. A pig dies after `minutesToDie` minutes if it drinks poison. You must determine the **minimum pigs needed** within total testing time. ([LeetCode][1])

---

# 🧠 Core Insight (Most Important Concept)

Each pig can have multiple outcomes:

Example:

If total rounds =

[
\text{rounds} = \frac{\text{minutesToTest}}{\text{minutesToDie}}
]

Then each pig has:

[
\text{states} = \text{rounds} + 1
]

possible outcomes (dies in round 1, round 2, … or survives). ([AlgoMonster][2])

So with `p` pigs:

[
(\text{states})^p \ge \text{buckets}
]

We must find minimum `p`.

---

# ✅ Mathematical Formula (Final Result)

Let:

[
\text{states} = \frac{\text{minutesToTest}}{\text{minutesToDie}} + 1
]

Then:

[
\text{states}^p \ge \text{buckets}
]

Solve minimum `p`.

---

# ✅ Algorithm (Optimal Approach)

Steps:

1. Compute number of rounds:

```
rounds = minutesToTest / minutesToDie
```

2. Compute states:

```
states = rounds + 1
```

3. Start with:

```
pigs = 0
capacity = 1
```

4. While:

```
capacity < buckets
```

update:

```
capacity *= states
pigs++
```

5. Return pigs

---

# ✅ C++ Code (Interview Standard)

```cpp
#include <iostream>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int states = minutesToTest / minutesToDie + 1;
        
        int pigs = 0;
        long long capacity = 1;
        
        while (capacity < buckets) {
            capacity *= states;
            pigs++;
        }
        
        return pigs;
    }
};
```

---

# ⏱️ Complexity Analysis

* **Time Complexity:** O(log(buckets))
* **Space Complexity:** O(1) ([heycoach.in][3])

Very efficient solution.

---

# 📊 Example Walkthrough (Important)

Example:

```
buckets = 1000
minutesToDie = 15
minutesToTest = 60
```

Step 1:

```
rounds = 60 / 15 = 4
```

Step 2:

```
states = 4 + 1 = 5
```

Now solve:

```
5^p ≥ 1000
```

Try values:

```
5¹ = 5
5² = 25
5³ = 125
5⁴ = 625
5⁵ = 3125 ✅
```

So answer:

```
p = 5 pigs
```

Matches expected output. ([GeeksforGeeks][4])

---

# 🧩 Why This Works (Interview Explanation)

Each pig behaves like a **digit in base-states number system**.

Example:

If states = 5 and pigs = 2

You can uniquely identify:

```
5² = 25 buckets
```

Similarly:

```
states^p buckets
```

So we encode bucket index using pigs as digits.

---

# ⭐ Alternative Formula Version (Logarithmic)

Direct formula:

[
p = \lceil \log_{states}(buckets) \rceil
]

Equivalent implementation:

```cpp
#include <cmath>

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    
    int states = minutesToTest / minutesToDie + 1;
    
    return ceil(log(buckets) / log(states));
}
```

---

# 📊 Summary Table

| Concept         | Formula                      |
| --------------- | ---------------------------- |
| Rounds          | minutesToTest / minutesToDie |
| States per pig  | rounds + 1                   |
| Buckets covered | states^pigs                  |
| Goal            | states^pigs ≥ buckets        |

---

# 🧠 Interview Tip

This is **not simulation** or **DP**.

It’s actually:

* combinatorics
* number system encoding
* logarithmic search space compression

Recognizing this quickly is the key to solving the problem in interviews.

[1]: https://leetcode.com/problems/poor-pigs/?utm_source=chatgpt.com "Poor Pigs"
[2]: https://algo.monster/liteproblems/458?utm_source=chatgpt.com "458. Poor Pigs - In-Depth Explanation"
[3]: https://heycoach.in/blog/poor-pigs-solution-in-python/?utm_source=chatgpt.com "Poor Pigs Solution In Python"
[4]: https://www.geeksforgeeks.org/dsa/minimum-number-of-pigs-required-to-find-the-poisonous-bucket/?utm_source=chatgpt.com "Minimum number of pigs required to find the poisonous ..."

*/