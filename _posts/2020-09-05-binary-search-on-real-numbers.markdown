---
layout: post
title: Binary Search on real numbers
date: 2020-09-05 17:35
comments: true
external-url:
categories: Techniques
---

- We have two methods to decide the termination condition:
  1. Terminate when the search space gets smaller than some predetermined bound, ${(r-l)}\lt{10}^{-12} or {10}^{-9}$
  2. Do predetermined number of iterations eg. 200 or 300 iterations.
- More iterations will give more precision.
- If we do $200$ iterations, it will suffice for array of integers of size ${2}^{200}$.
- But for real numbers, $200$ iterations will mean that we divide the range of binary search ($R$) into $R/{2}^{200} segments$.

<br>

```cpp
bool check() {//your checker logic}

//Based on gap between l and r
long double binarySearchOnRealNumbers() {
     long double l = 0, r = 2000000020;
        while ((r - l) >= 0.000000001) {
            long double mid = (l + r) / 2;
            if (check()) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
}

//Based on number of iterations
long double binarySearchOnRealNumbers() {
     long double l = 0, r = 2000000020;
     int i = 0;
        while (i++ <= 300 ) {
            long double mid = (l + r) / 2;
            if (check()) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
}
```

## Problems:

[Alien Invasion(Codechef)](https://www.codechef.com/LTIME87A/problems/ALIENIN).<br>
