# Linear Data Structures

<br>

## Index

1 . [Maximum element from each sub array of size k](#maximum-element-from-each-sub-array-of-size-k)

2 . [Number of sub arrays having sum exactly k](#number-of-subarrays-having-sum-exactly-k)

3 . [Longest Increasing Subsequence in NlgN](#longest-increasing-subsequence-in-NlgN)

4 . [Longest Increasing Subsequence of consecutive numbers](#longest-increasing-subsequence-of-consecutive-numbers)

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

Encountered as a subproblem in `Equal subarrays` in [January Circuits 2020(Hackerearth)](https://www.hackerearth.com/challenges/competitive/january-circuits-20/).

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
  _f<sub>r</sub> op<sup>-1</sup> f<sub>l</sub>_ = _f<sub>(l+1....r)</sub>_ where _op<sup>-1</sup>_ is the inverse of _op_ operator.<br>

Variation encountered in [A. Sasha and a Bit of Relax(Codeforces)](https://codeforces.com/problemset/problem/1109/A).

<br>

## Longest Increasing Subsequence in NlgN

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

Also refer - [Longest Increasing Subsequence in Nlog<sub>2</sub>N using segment tree](/notes/NonLinearDataStructures.md#longest-increasing-subsequence-using-nlgn)

<br>

## Longest Increasing Subsequence of consecutive numbers

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

Also refer - [Longest Increasing Subsequence in Nlog<sub>2</sub>N using segment tree](/notes/NonLinearDataStructures.md#longest-increasing-subsequence-using-nlgn)
