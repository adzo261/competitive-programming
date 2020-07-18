# Linear Data Structures

<br>

## Index

1 . [Maximum element from each sub array of size k](#maximum-element-from-each-sub-array-of-size-k)

2 . [Number of sub arrays having sum exactly k](#number-of-subarrays-having-sum-exactly-k)

---

<br>

## Maximum element from each sub array of size k

Example: <br>
Input:
{1,9,3,4,5,6},
k = 2 <br>
Output:
{9,9,4,5,6}

```cpp
vector<long long> maxOfEachSubArray(vector<long long> a, int k) {
    int n = a.size();
    vector<long long> ans;

    //Using double ended queue
    // Maximum element for current subarray stored at front
    deque<int> dq;
    dq.push_back(0);
    int c = k - 1;

    //When k = 1, need to push first element
    if (c == 0) {
        ans.push_back(a[0]);
        c++;
    }
    for (int i = 1; i < n; i++) {
        //When Deque's front element is out of scope of current subarray considered
        if (i > (dq.front() + k - 1)) {
            dq.pop_front();
        }
        /*While current element is greater than smallest elements of queue,
         remove smallest elements from queue*/
        while (!dq.empty() && a[i] > a[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);

        //Neat trick to insert max element from queue for each subarray
        if (i == c) {
            ans.push_back(a[dq.front()]);
            c++;
        }
    }
    return ans;
}

```

- Encountered as a subproblem in `Equal subarrays` in [January Circuits 2020(Hackerearth)](https://www.hackerearth.com/challenges/competitive/january-circuits-20/).

<br>

## Number of subarrays having sum exactly k

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
  _f<sub>r</sub> op<sup>-1</sup> f<sub>l</sub>_ = _f<sub>(l+1....r)</sub>_ where _op<sup>-1</sup>_ is the inverse of _op_ operator.
- Variation encountered in [A. Sasha and a Bit of Relax(Codeforces)](https://codeforces.com/problemset/problem/1109/A).
