---
layout: post
title: Longest Increasing Subsequence in NlgN
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
5

```cpp
ll lis(vector<ll> a) {
    vector<ll> s;

    for (auto x : a) {
        auto it = lower_bound(s.begin(), s.end(), x);
        //Change lower_bound to upper_bound for lnds
        if (it == s.end()) {
            s.push_back(x);
        } else {
            *it = x;
        }
    }
    return s.size();
}
```

#### Idea:

- Vector $s$ represents the elements of the $lis$ till now
- We find the first element in $s$ greater than or equal to new element $x$ and replace that element with $x$ if found else push into $s$.
- Assume we have $b \geq x$, and the elements in $s$ are $\{a, b, c\}$, then since we want the longest $lis$ to be in vector $s$, we want each element in $s$ to be as small as possible.
- Hence, we replace, $b$ with $x$ since, $a < x$ because $b$ is the first element such that $b \geq x$ and $x \leq b < c$.
- Now, $\{a, x, c \}$ is the $lis$ of same length with each element in it smaller or equal than $\{a , b , c\}$.
- And when we dont find such a $b$, we simply push $x$ in the vector, since $x$ will be new largest element of the $lis$ now.

Also refer - [Longest Increasing Subsequence in Nlog<sub>2</sub>N using segment tree](/competitive-programming/blog/2020/08/03/longest-increasing-subsequence-in-NlgN-using-segment-trees/)
