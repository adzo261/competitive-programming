#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[210];
long long dp[210][210][210];
long long unpainted(long long ind,long long inc,long long dec)
{
	if(ind==n)
		return 0;
	if(dp[ind][inc][dec]!=-1)
		return dp[ind][inc][dec];	
	long long ta,tb,tc;
	ta=tb=tc=1000000000;
	 ta=1+unpainted(ind+1,inc,dec);
	if(a[ind]>a[inc])//|| inc==(0))
		tb=unpainted(ind+1,ind,dec);
	if(a[ind]<a[dec])//|| dec==(0))
		tc=unpainted(ind+1,inc,ind);

	dp[ind][inc][dec]=min(ta,min(tb,tc));
	return dp[ind][inc][dec];
}
int main()
{
	
	while(true)
	{
		scanf("%lld",&n);
		if(n==-1)
			break;
		memset(dp,-1,sizeof(dp));
		memset(a,0,sizeof(a));
		vector<pair<long long,long long>> v;
		
		for(int i=0;i<n;i++)
		{	
			long long tt;
			scanf("%lld",&tt);
			v.push_back({tt,i});
		}
		sort(v.begin(),v.end());
		int r=1;
		a[v[0].second]=r++;
		for(int i=1;i<n;i++)
		{
			if(v[i].first>v[i-1].first)
				a[v[i].second]=r++;
			else
				a[v[i].second]=r-1;
		}
		a[205]=-10000000000;
		a[206]=10000000000;
		printf("%lld\n", unpainted(0,205,206));
		
	}









	return 0;
}