#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
const int N = 50;
int dp[N];

/*
dp[i]=min cost to reach n-1 starting from i with first letter road[i],
and the series starting with road[i].
For eg. if road[i]='R',series=> R-G-B
		if road[i]='G',series=> G-B-R
		if road[i]='B' ,series=> B-R-G

	Then recurrence is as follows:
	dp[n-1]=0;
	if(i<n-1)
	dp[i]=min(dp[i],(j-i)^2+dp[j]) for all j from i+1 to n-1 provided road[j] is the next of road[i] series.
*/
class ColorfulRoad
{
  public:
	int getMin(string road)
	{
		const int INF = 100000;

		const int n = road.length();
		unordered_map<char, char> next = {{'R', 'G'}, {'G', 'B'}, {'B', 'R'}};
		dp[n - 1] = 0;

		for (int i = n - 2; i >= 0; i--)
		{
			dp[i] = INF;
			for (int j = i + 1; j < n; j++)
			{
				if (road[j] == next[road[i]])
					dp[i] = min(dp[i], (j - i) * (j - i) + dp[j]);
			}
		}

		return (dp[0] >= INF ? -1 : dp[0]);
	}
};
