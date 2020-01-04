#include <bits/stdc++.h>
using namespace std;
int dp[5010][5010];
char s[5010];
int main()
{

	int n;
	scanf("%d",&n);
	scanf("%s",s);
	

if(s[0]==s[n-1])
	dp[0][0]=1;
else
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=(i==0)?1:0;j<n;j++)
		{	
			
				if(s[i]==s[n-1-j])
				dp[i][j]=1+((i>0 && j>0)?dp[i-1][j-1]:0);//cout<<i<<" "<<(n-1-j)<<endl;
				else
				dp[i][j]=max((i>0 )?dp[i-1][j]:0,(j>0)?dp[i][j-1]:0);
			
		}
	}
	//cout<<dp[0][1]<<endl;
	printf("%d\n",(n-dp[n-1][n-1]));









	return 0;
}