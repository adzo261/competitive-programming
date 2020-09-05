---
layout: post
title: Longest Increasing Subsequence of consecutive numbers
date: 2020-08-03 18:00
comments: true
external-url:
categories: Linear-Data-Structures
---

Example: <br><br>
Input:
{ 1, 6, 4, 2, 3, 12, 15, 4 }
<br>
Output:
4

## Version 1 : Distinct Elements

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

<br><br>

## Version 2: May or may not be distinct

```cpp
map<ll, ll> mp;
//mp[x] stores the length of longest increasing consecutive subsequence ending at element x

ll lisOfConsecutiveNos(vector<ll> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        mp[a[i]] = mp[a[i] - 1] + 1;
    }
    ll lastElement = -1;
    ll ans = 0;

    for (auto p : mp) {
        if (ans < p.second) {
            ans = p.second;
            lastElement = p.first;
        }
    }
    vector<ll> indices; //stores the subsequence

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == lastElement) {
            indices.push_back(i + 1);
            lastElement--;
        }
        if (lastElement == 0) {
            break;
        }
    }
    reverse(indices.begin(), indices.end());

    return ans;
}
```

#### Idea:

- $mp[x]$ stores the length of the longest consecutive subsequence ending at element $x$.
- Now we can use an easy recurrence, $mp[x] = mp[x-1] + 1$, while iterating through vector $a$.
- We are sure that its a subsequence because when we encounter $x$ at current position in $a$ say $i$, we are looking at if there was a subsequence ending at $x-1$ till now, i.e before the ${i}^{th}$ position.

<br><br>

## Problems:

[A. Sorting Railway Cars(Codeforces)](https://codeforces.com/contest/605/problem/A).<br>
[F. Consecutive Subsequence(Codeforces)](https://codeforces.com/problemset/problem/977/F).
