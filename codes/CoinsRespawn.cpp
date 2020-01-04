#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
vector<pair<int, long long>> g[3000];
vector<int> gr[3000];
bool reachableFromN[3000];

void bfs(int src)
{
	reachableFromN[src] = true;
	queue<int> q;
	q.push(src);

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		for (auto ne : gr[curr])
		{
			if (ne != curr)
			{
				if (!reachableFromN[ne])
				{
					reachableFromN[ne] = true;
					q.push(ne);
				}
			}
		}
	}
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m, p;
	cin >> n >> m >> p;

	for (int i = 0; i < m; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		c -= p;
		g[a].push_back({b, c});
		gr[b].push_back(a);
	}

	bfs(n - 1);

	//Bellman Ford O(V*E):Finds shortest paths from src to all vertices in V-1 passes if no neg cycle
	long long dist[n];
	long long NMAX = -1000000000000000000;
	fill(dist, dist + n, NMAX);
	/* 	print(dist, 0, n); */
	dist[0] = 0;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (dist[j] == NMAX)
				continue;
			for (auto edge : g[j])
			{
				if (dist[edge.first] < (dist[j] + edge.second))
				{
					dist[edge.first] = (dist[j] + edge.second);
				}
			}
		}
	}

	//If we can relax for more than V-1, i.e Vth time, then neg cycle exists
	for (int j = 0; j < n; j++)
	{
		if (dist[j] == NMAX)
			continue;
		for (auto edge : g[j])
		{

			if (dist[edge.first] == NMAX)
				continue;

			if (dist[edge.first] < (dist[j] + edge.second) && reachableFromN[edge.first])
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << max(0ll, dist[n - 1]) << endl;

	return 0;
}