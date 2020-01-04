#include <bits/stdc++.h>
using namespace std;
 //Compiler version g++ 6.3.0
vector<int> dp[110];
vector<int> a[110];
int n;

int find(int i,int j)
{
	if(dp[i][j]!=0)
	return dp[i][j];
	else
	{
		dp[i][j]=a[i][j]+
		max(((i+1)<n)
			?(find(i+1,j)):(0),
		((i+1)<n)
			?(find(i+1,j+1)):(0)	
			);
		return dp[i][j];
	}
}
 int main()
 {
 	int t;
 	cin>>t;
 	
 	while(t--)
 	{
 		cin>>n;
 		for(int i=0;i<n;i++)
 		{  
 			for(int j=0;j<i+1;j++)
 			{
 			  dp[i].push_back(0);
 			}
 			
 		} 
 		for(int i=0;i<n;i++)
 		{ 
 			for(int j=0;j<i+1;j++)
 			{ 
 				int k;
 				cin>>k;
 				a[i].push_back(k);
 			}
 		
 		}
 		
 		cout<<find(0,0)<<endl;
 		for(int i=0;i<110;i++)
 		dp[i].clear(),a[i].clear();
 	}
 	
 	return 0;
 }