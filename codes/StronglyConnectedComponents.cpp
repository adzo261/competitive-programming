#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r)          \
	for (int i = l; i < r; i++) \
		cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;
const int N = 1010;
vector<int> g[N], rg[N];
stack<int> max_end_time_sinks;
vector<bool> visited;

//Kosaraju's Linear time algorithm to find Strongly Connected Components:
//O(V+E) two passes of dfs
//refer https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/

//To get end times of dfs nodes
void dfs(int s)
{
	visited[s] = true;

	for (auto e : g[s])
	{
		if (!visited[e])
			dfs(e);
	}

	max_end_time_sinks.push(s);
}

//To get scc using reverse graph

int dfs1(int s)
{
	visited[s] = true;
	int ans = 1;
	for (auto e : rg[s])
	{
		if (!visited[e])
		{
			int p = dfs1(e);
			ans += p;
		}
	}

	return ans;
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		g[i].clear();
		rg[i].clear();
		visited.push_back(false);
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
			dfs(i);
	}
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	int C = 0, D = 0;

	while (!max_end_time_sinks.empty())
	{
		int node = max_end_time_sinks.top();
		max_end_time_sinks.pop();

		if (!visited[node])
		{
			auto p = dfs1(node);
			if (p % 2)
				C += p;
			else
				D += p;
		}
	}

	cout << (C - D) << endl;
	return 0;
}