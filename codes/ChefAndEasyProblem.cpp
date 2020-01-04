#include <bits/stdc++.h>
using namespace std;
int main()
{

	int n,q;
	cin>>n>>q;
	string a[n];
	long long dp[n][31];
	for(int i=0;i<n;i++)
		{
			long long temp;
			cin>>temp;
			a[i]=bitset<31>(temp).to_string();
		}
		for(int i=0;i<31;i++)
			dp[0][i]=(a[0][i]=='1')?1:0;

		for(int i=1;i<n;i++)
		{

			for(int j=0;j<31;j++)
			{
				dp[i][j]=((a[i][j]=='1')?1:0) +dp[i-1][j];

			}
		}
		/*for(int i=0;i<n;i++)
		{

			for(int j=0;j<31;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}*/
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--,r--;
		//long long g=2147483647;
		//long long ans=-100000000000000000;
		string ans;
		for(int i=30;i>=0;i--)
		{
				 if((dp[r][i]-((l>0)?(dp[l-1][i]):0))<ceil(((long double)(r-l+1))/2))
					ans="1"+ans;
				 else
					ans="0"+ans;
			
		}
		cout<<bitset<31>(ans).to_ullong()<<endl;
		
	}

	return 0;
}