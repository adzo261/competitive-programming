#include <bits/stdc++.h>
using namespace std;
int main()
{	
	vector<long long> dp;
	dp.push_back(0);
	long long n;

	while(scanf("%lld",&n)==1)
	{	
		if(dp.size()>=n+1)
			cout<<dp[n]<<endl;
		else
		{
			for(long long i=dp.size();i<=n;i++)
		{
			dp.push_back(max(i,(dp[i/2]+dp[i/3]+dp[i/4])));
		}

		/*for(long long int i=0;i<=n;i++)
		{
			cout<<dp[i]<<" ";
		}*/
		cout<<dp[n]<<endl;
		}
	}








	return 0;
}