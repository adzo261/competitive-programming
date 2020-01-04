#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int mask[10] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		pair<int, int> a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i].first >> a[i].second;

		int mn = 100, mx = -1;
		bool done = false;
		for (int i = 0; i < (1 << 7); i++)
		{
			bool valid = true;
			for (int j = 0; j < n; j++)
			{

				if (__builtin_popcount((mask[a[j].first] & i)) != a[j].second)
				{
					valid = false;
					break;
				}
			}

			if (valid)
			{

				done = true;
				int dead = 7 - __builtin_popcount(i);
				mn = min(mn, dead);
				mx = max(mx, dead);
			}
		}
		if (done)
			cout << mn << " " << mx << endl;
		else
			cout << "invalid" << endl;
	}
	return 0;
}