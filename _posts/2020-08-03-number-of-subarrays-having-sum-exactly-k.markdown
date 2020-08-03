---
layout: post
title: Number of sub arrays having sum exactly k
date: 2020-08-03 18:00
comments: true
external-url:
categories: Linear-Data-Structures
---

Example: <br>
Input:
{ 1,2,1,2,4,2 },
k = 4 <br>
Output:
2

```cpp
ll numberOfSubarraysWithSumK(vector<ll> a, ll k) {
    //mp[x] stores number of subarrays having sum x till now
    unordered_map<ll, ll> mp;

    ll ans = 0;

    // sum of elements till now
    ll sum = 0;

    for (ll i = 0; i < a.size(); i++) {
        // Add current element to sum
        sum += a[i];

        // If sum = k, new sub array found, increase ans
        if (sum == k)
            ans++;

        //If sum  > k, find all subarrays having sum as 'sum-k' till now
        // For eg if  i........j..........l...
        //If index i to j forms a sub array having (sum-k) and we are currently at index 'l'
        //where sum till l is 'sum'
        // Then j+1......l subarray has sum k
        // Hence we add all count of subarrays having sum 'sum-k' till now to ans,
        //since each will make 'k' sum subarray as shown above
        if (mp.find(sum - k) != mp.end())
            ans += (mp[sum - k]);

        // Add sum value to count of
        // different values of sum.
        mp[sum]++;
    }

    return ans;
}

```

- Can be used on a function _f_ : _f_ be the cumulative function on array _a_ using operator _op_,<br>
  then if _f_ follows :<br>
  _f<sub>r</sub> op<sup>-1</sup> f<sub>l</sub>_ = _f<sub>(l+1....r)</sub>_ where _op<sup>-1</sup>_ is the inverse of _op_ operator.<br>

Variation encountered in [A. Sasha and a Bit of Relax(Codeforces)](https://codeforces.com/problemset/problem/1109/A).
