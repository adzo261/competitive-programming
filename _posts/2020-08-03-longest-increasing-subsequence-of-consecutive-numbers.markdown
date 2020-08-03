---
layout: post
title: Longest Increasing Subsequence of consecutive numbers
date: 2020-08-03 18:00
comments: true
external-url:
categories: Linear-Data-Structures
---

Example: <br>
Input:
{ 1, 6, 4, 2, 3, 12, 15, 4 }
<br>
Output:
4

```cpp
const ll N = 100010;
ll f[N];
ll lisOfConsecutiveNos(vector<ll> a) {
    ll mx = -1;
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        f[a[i]] = i + 1;
        mx = max(mx, a[i]);
    }
    ll maxSubsegment = 1;
    ll c = 1;
    for (int i = 2; i <= mx; i++) {
        if (f[i] > f[i - 1]) {
            c++;
        } else {
            maxSubsegment = max(maxSubsegment, c);
            c = 1;
        }
    }
    if (c > 1) {
        maxSubsegment = max(maxSubsegment, c);
    }
    return maxSubsegment;
}
```

#### Idea:

- $f[x]$ represents the position of element $x$ in original vector $a$.
- Now if we look at any consecutive subsegment of array $f$, its indices are consecutive numbers, but to make sure that those form a subsequence in original vector $a$, the corresponding values of those indices should be in increasing order.
- Formally, Let $i$ be the set of indices for $f[i]$ such that $\{i : j,j+1,j+2,...j+k\}$ then,
  the $f[i] < f[i+1]$ must hold for any $i$ such that $\{i:j,j+1,j+2,..j+k-1\}$ for the elements in set $i$ to be subsequence of original vector $a$.
- Therefore, the $lis$ of consecutive elements in vector $a$ will be the longest increasing subsegment of array $f$.

Encountered in [A. Sorting Railway Cars(Codeforces)](https://codeforces.com/contest/605/problem/A).
