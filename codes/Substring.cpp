	#include <bits/stdc++.h>
	using namespace std;
	#define endl "\n"
	const long long M=1000000007;
	set<long long> g[300010];
	bool visited[300010];
	bool recStack[300010];
	vector<long long> order;

	//Detect cycle in an directed graph
	bool dfs(long long s)
	{
		visited[s]=true;
		recStack[s]=true;
		for(auto e:g[s])
		{
			if(!visited[e] && dfs(e) || recStack[e])
					return true;
			
		}
		recStack[s]=false;
		return false;
	}
	void dfs1(long long s)
	{
		visited[s]=true;
		
		for(auto e:g[s])
		{	
			if(!visited[e])
					dfs1(e);
		}
		order.push_back(s);
	}
	
	int main() 
	{
		
		ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	long long n,m;
    	cin>>n>>m;
    	memset(visited,0,sizeof(visited));
    	memset(recStack,0,sizeof(recStack));
    	string s;
    	cin>>s;

    	for(int i=0;i<m;i++)
    	{
    		long long a,b;
    		cin>>a>>b;
    		g[a-1].insert(b-1);
    	}

    	bool cycle=false;

    	for(int i=0;i<n;i++)
    	{
    		if(!visited[i])
    			cycle=dfs(i);
    		if(cycle)
    			break;
    	}
    	if(cycle)
    		cout<<-1<<endl;
    	else
    	{
    		
	    	long long dp[n][26];
	    	memset(dp,0,sizeof(dp));
	    	memset(visited,0,sizeof(visited));

	    	//dp[i][j] means the maximum number of frequently occurring character('a'+j) on paths starting from i 

	    	for(int i=0;i<n;i++)
	    	{	
	    			if(!visited[i])
	    			{
		    				dfs1(i);
		    		}
		    }
		    			
			dp[order[0]][s[order[0]]-'a']=1; 	
			 for(int ord=1;ord<order.size();ord++)
				 {	
				    for(int j=0;j<26;j++)
		    			dp[order[ord]][j]+=(j==(s[order[ord]]-'a'));
		    
		    		for(auto e :g[order[ord]])
					    {	
					    	for(int j=0;j<26;j++)
					    	{
					    		dp[order[ord]][j]=max(dp[order[ord]][j],dp[e][j]+(j==(s[order[ord]]-'a')));
					    	}
					    }
					    		
				}
			    
	    	long long ans=-1;
	    	for(int i=0;i<n;i++)
	    		{
	    			for(int j=0;j<26;j++)
	    			ans=max(ans,dp[i][j]);
	    		}

	    		cout<<ans<<endl;
	     }
 


			
		return 0;
	}