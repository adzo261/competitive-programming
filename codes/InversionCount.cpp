#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
const long long AN = 10000010;
long long tree[4 * AN];

void update(long long node, long long start, long long end, long long index)
{
	if (start > end)
		return;
	if (start == end && start == index)
	{
		tree[node]++;
		return;
	}

	long long mid = (start + end) >> 1;

	if (index <= mid)
		update(2 * node, start, mid, index);
	else
		update(2 * node + 1, mid + 1, end, index);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long query(long long node, long long start, long long end, long long l, long long r)
{
	if (start > end || start > r || end < l)
		return 0;
	if (l <= start && end <= r)
	{
		return tree[node];
	}

	long long mid = (start + end) >> 1;

	return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		fill(tree, tree + 4 * AN, 0);
		long long n;
		cin >> n;
		long long a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += query(1, 1, (long long)1e7, a[i] + 1, (long long)1e7);
			update(1, 1, (long long)1e7, a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}