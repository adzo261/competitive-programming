#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;
	cin>>n;
	long long dp[31]={0};

	for(int i=0;i<n;i++)
	{
		long long a;
		cin>>a;
		string s=bitset<31>(a).to_string();
		for(int j=0;j<31;j++)
			if(s[j]=='1')
				dp[30-j]++;
	}
	long long ans=0;
	for(int i=30;i>=0;i--)
	{	//cout<<dp[i]<<endl;
		if(dp[i]>=2)
		ans+=dp[i]*(dp[i]-1)*0.5*(long long)pow(2,i);
	}
	cout<<ans<<endl;





	return 0;
}