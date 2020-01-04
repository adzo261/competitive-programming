#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
const long long N = 200;
long long visited[N];
long long tin[N];
long long low[N];
set<long long> cut_points;
vector<long long> g[N];
int timer = 0;

void dfs(long long p, long long s)
{

	visited[s] = true;
	tin[s] = low[s] = timer++;
	int children = 0;
	for (auto e : g[s])
	{
		if (e == p)
			continue;
		if (visited[e])
		{
			low[s] = min(low[s], tin[e]);
		}
		else
		{
			dfs(s, e);
			low[s] = min(low[s], low[e]);

			if (low[e] >= tin[s] && p != -1)
				cut_points.insert(s + 1);

			children++;
		}
	}

	if (p == -1 && children > 1)
		cut_points.insert(s + 1);
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;

		fill(visited, visited + n, false);
		fill(tin, tin + n, -1);
		fill(low, low + n, -1);

		for (int i = 0; i < n; i++)
			g[i].clear();

		cut_points.clear();
		timer = 0;
		cin.ignore();
		while (true)
		{
			vector<long long> temp;
			string line;
			getline(cin, line);
			istringstream iss(line);

			long long v;
			while (iss >> v)
			{
				if (v == 0)
					break;
				temp.push_back(v);
			}
			if (v == 0)
				break;
			for (int i = 1; i < temp.size(); i++)
			{
				g[temp[0] - 1].push_back(temp[i] - 1);
				g[temp[i] - 1].push_back(temp[0] - 1);
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
				dfs(-1, i);
		}

		cout << cut_points.size() << endl;
	}

	return 0;
}