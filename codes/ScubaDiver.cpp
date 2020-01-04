#include <bits/stdc++.h>
using namespace std;
int main()
{

	int t;
	cin>>t;

	while(t--)
	{

		long long O,N;
		cin>>O>>N;

		int nn;
		cin>>nn;
		long long o[nn],n[nn],w[nn];
		for(int i=0;i<nn;i++)
		{
			cin>>o[i]>>n[i]>>w[i];
		}
		long long dp[nn][O+1][N+1];
		for(int i=0;i<nn;i++)
		{
			for(int j=0;j<=O;j++)
			{
				for(int k=0;k<=N;k++)
				{
					dp[i][j][k]=10000000000;
					if(j==0 && k==0)
						dp[i][j][k]=0;
				}
			}
		}

	 for (int j = 0; j <= O; j++)
      for (int k = 0; k <= N; k++)
        if (j <= o[0] && k <= n[0] && (j > 0 || k > 0)) {
          dp[0][j][k] = w[0];
        }

		for(int i=1;i<nn;i++)
		{
			for(int j=0;j<=O;j++)
			{
				for(int k=0;k<=N;k++)
				{
					
					if(j<=o[i] && k<=n[i])
						dp[i][j][k]=min(dp[i-1][j][k],w[i]);
					else
						dp[i][j][k]=min(dp[i-1][j][k],w[i]+dp[i-1][max(0LL,(j-o[i]))][max(0LL,(k-n[i]))]);
		
						

				}
			}
		}

		cout<<dp[nn-1][O][N]<<endl;
	}






	return 0;
}