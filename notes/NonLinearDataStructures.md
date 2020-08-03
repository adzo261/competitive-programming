# Non Linear Data Structures

<br>

## Index

1 . [Longest Increasing Subsequence in Nlog<sub>2</sub>N](#longest-increasing-subsequence-using-nlgn)

---

<br>

## Longest Increasing Subsequence in Nlog<sub>2</sub>N

Example: <br>
Input:
{ 1, 6, 4, 2, 3, 12, 15, 4 },
<br>
Output:
5

```cpp
#define N 100010
ll tree[4 * N];
ll d[N];
ll query(ll node, ll start, ll end, ll l, ll r) {
    if (start > end || r < start || end < l)
        return 0;
    if (l <= start && end <= r)
        return tree[node];

    ll mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}
void update(ll node, ll start, ll end, ll ind, ll value) {
    if (start > end)
        return;

    if (start == end && start == ind) {
        tree[node] = value;
        return;
    }
    ll mid = (start + end) / 2;
    if (ind <= mid)
        update(2 * node, start, mid, ind, value);
    else
        update(2 * node + 1, mid + 1, end, ind, value);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
ll lis(vector<ll> a) {
    ll ans = 0;
    ll mx = -1;
    for (auto x : a) {
        mx = max(mx, x);
    }
    for (auto x : a) {
        d[x] = query(1, 1, mx, 1, x - 1) + 1;
        update(1, 1, mx, x, d[x]);
        ans = max(ans, d[x]);
    }

    return ans;
}
```

#### Idea:

- $d[x]$ stores the length of $lis$ ending at $x$.
- We make use of recurrence, $d[x] = max(\{d[i] : i = 1,....x-1\}) + 1$.
- For this we maintain a max segment tree with range $[1, mx]$, where $mx = max(\{a[i] : i = 1,....,n\})$ and based on array $d$.
- We query for $max(\{d[i] : i = 1,....x-1\})$ using segment tree and then update $d[x] = maxValue + 1$ and then update segment tree at index $x$ with new $d[x]$.
- While doing this we keep updating the max value of $d[x]$ till now which is the actual answer.

  <br>

Encountered in [D. Bubble Sort Graph(Codeforces)](https://codeforces.com/problemset/problem/340/D).<br>
Also refer - [Longest Increasing Subsequence in Nlog<sub>2</sub>N using binary search](/notes/LinearDataStructures.md#longest-increasing-subsequence-using-nlgn)
