#include <bits/stdc++.h>
using namespace std;
#define N 100010

long long dp[N][2];
vector<long long> g[N];

long long dfs(long long c,long long p)
{
	dp[c][1]=1;

	for(int i=0;i<g[c].size();i++)
	{
		if(g[c][i]!=p)
		{	
			dfs(g[c][i],c);
			dp[c][1]+=min(dp[g[c][i]][1],dp[g[c][i]][0]);
			dp[c][0]+=dp[g[c][i]][1];
		}
	}
}
int main()
{

int n;
cin>>n;

for(int i=0;i<n-1;i++)
{
	long long a,b;
	cin>>a>>b;

	g[a].push_back(b);
	g[b].push_back(a);

}
	dfs(1,0);
	//cout<<dp[1][1]<<" "<<dp[1][0]<<endl;
	cout<<max(1LL,min(dp[1][1],dp[1][0]))<<endl;











	return 0;
}