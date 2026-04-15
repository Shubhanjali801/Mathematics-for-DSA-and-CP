// Sieve of Eratosthenes. Mark composites from p² in steps of p. O(n log log n).
// 🔍 Why Google asks: Google asks this to check if you know Sieve vs brute-force O(n√n).


/*

* Algorithm steps
* C++ code
* Time Complexity (TC)
* Space Complexity (SC)

---
Ques : Given number is prime of not or count number of prime numbers which is lesss than n

# ✅ Method 1: Brute Force (Check from 1 to N)

### Idea

A prime number has exactly **2 factors: 1 and itself**.
Count total factors from `1 → N`.

### Algorithm

1. Input number `n`
2. Initialize `count = 0`
3. Loop from `1 to n`
4. If `n % i == 0`, increment count
5. If `count == 2`, prime else not prime

### C++ Code

```cpp
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;

    int count = 0;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
            count++;
    }

    return (count == 2);
}

int main()
{
    int n;
    cin >> n;

    if(isPrime(n))
        cout << "Prime";
    else
        cout << "Not Prime";
}
```

### Complexity

* **TC:** O(n)
* **SC:** O(1)

---

# ✅ Method 2: Optimized Brute Force (Check till N/2)

### Idea

No divisor of `n` (except itself) can be greater than `n/2`.

### Algorithm

1. If `n <= 1`, return false
2. Loop from `2 to n/2`
3. If divisible → not prime
4. Else prime

### C++ Code

```cpp
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;

    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}
```

### Complexity

* **TC:** O(n/2) ≈ O(n)
* **SC:** O(1)

---

# ✅ Method 3: Square Root Optimization (Most Important for Interviews ⭐)

### Idea

Factors always appear in **pairs**:

Example:

```
36 → (1,36), (2,18), (3,12), (4,9), (6,6)
```

So check only till:

[
\sqrt{n}
]

i \leq \sqrt{n}

### Algorithm

1. If `n <= 1`, return false
2. Loop from `2 to sqrt(n)`
3. If divisible → not prime
4. Else prime

### C++ Code

```cpp
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;

    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}
```

### Complexity

* **TC:** O(√n) ✅ Best standard solution
* **SC:** O(1)

---

# ✅ Method 4: Further Optimization (Skip Even Numbers)

### Idea

After checking `2`, check only **odd numbers**

### Algorithm

1. If `n <= 1`, return false
2. If `n == 2`, return true
3. If `n % 2 == 0`, return false
4. Loop from `3 to sqrt(n)` with step `2`

### C++ Code

```cpp
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;

    if(n == 2)
        return true;

    if(n % 2 == 0)
        return false;

    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}
```

### Complexity

* **TC:** O(√n / 2) ≈ O(√n)
* **SC:** O(1)

---

# ✅ Method 5: Sieve of Eratosthenes (For Multiple Queries)

Best when checking primes **from 1 to N** (not single number).

### Idea

Mark multiples as non-prime.

Example:

```
2 → remove 4,6,8,10...
3 → remove 6,9,12...
```

### Algorithm

1. Create array `prime[n+1]`
2. Initialize all true
3. Start from `2`
4. Mark multiples false
5. Remaining true values are primes

### C++ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n)
{
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;

    for(int i = 2; i * i <= n; i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++)
    {
        if(prime[i])
            cout << i << " ";
    }
}
```

### Complexity

* **TC:** O(n log log n)
* **SC:** O(n)

---

# ✅ Method 6: Fermat’s Primality Test (Advanced / Competitive Programming)

Used for **very large numbers**.

Formula:

If `n` is prime:

[
a^{n-1} \equiv 1 \pmod{n}
]

### Complexity

* **TC:** O(k log n)
* **SC:** O(1)

(Not commonly required in interviews unless advanced CP)

---

# 📊 Comparison Table

| Method            | TC             | SC   | Best Use Case             |
| ----------------- | -------------- | ---- | ------------------------- |
| Count factors     | O(n)           | O(1) | Beginner learning         |
| Check till n/2    | O(n)           | O(1) | Slight improvement        |
| Check till √n     | O(√n)          | O(1) | Interview standard ⭐      |
| Skip even numbers | O(√n)          | O(1) | Faster practical solution |
| Sieve             | O(n log log n) | O(n) | Multiple prime queries    |
| Fermat Test       | O(k log n)     | O(1) | Very large numbers        |

---

If you're preparing for **coding interviews (Striver A2Z level)**, Method **3 and 4** are the ones you should master first. 🚀

*/