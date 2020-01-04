#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
long long s[100];
void generateSubsets(int start, int n, vector<long long> &v)
{
	for (long long mask = 0; mask < (1 << n); mask++)
	{
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (mask & (1 << i))
				sum += s[start + i];
		}
		v.push_back(sum);
	}
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, a, b;
	cin >> n >> a >> b;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	vector<long long> l, r;
	generateSubsets(0, n / 2, l);
	generateSubsets(n / 2, ((n & 1) ? (n / 2 + 1) : (n / 2)), r);
	sort(r.begin(), r.end());

	long long ans = 0;
	for (int i = 0; i < l.size(); i++)
	{
		int low = lower_bound(r.begin(), r.end(), a - l[i]) - r.begin();
		int high = upper_bound(r.begin(), r.end(), b - l[i]) - r.begin();
		ans += high - low;
	}
	cout << ans << endl;
	return 0;
}