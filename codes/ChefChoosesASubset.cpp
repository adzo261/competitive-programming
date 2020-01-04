	#include <bits/stdc++.h>
	using namespace std;
	const long long M=1000000007;
	const long long N=100100;
	long long n;
	vector<long long> g[N];
	long long head[N];
	long long size[N];
	long long parent[N];

	long long find(long long x)
	{
		long long temp=x;

		while(head[x]!=x)
		{
			x=head[x];
		}

		while(temp!=x)
		{
			long long tx=head[temp];
			head[temp]=x;
			temp=tx;
		}

	return x;
	}

	void doUnion(long long x,long long y)
	{
		long long rootx=find(x);
		long long rooty=find(y);

		if(rootx!=rooty)
		{
			if(size[rootx]<size[rooty])
			{
				head[rootx]=rooty;
				size[rooty]+=size[rootx];
			}
			else
			{
				head[rooty]=rootx;
				size[rootx]+=size[rooty];
			}
		}
	}
	
	void dfs(long long p,long long s)
	{
		parent[s]=p;
		for(auto x:g[s])
		{
			if(x!=p)
			{
				dfs(s,x);
			}
		}
	}
	int main() 
	{
		
	    
	    int t;
	    cin>>t;

	    while(t--)
	    {
	    	cin>>n;

	    	memset(head,0,n+10);
	    	memset(size,0,n+10);
	    	memset(parent,0,n+10);
	    	for(int i=1;i<=n;i++)
	    		g[i].clear(),head[i]=i,size[i]=1;
	    	for(int i=0;i<(n-1);i++)
	    	{
	    		long long x,y;
	    		cin>>x>>y;
	    		g[x].push_back(y);
	    		g[y].push_back(x);
	    	}
	    	dfs(0,1);
	    	long long gmx=0;
	    	for(int i=1;i<=n;i++)
	    		{
	    			
	    			long long mx=0;
	    			//Used to iterate over supermasks of i,
	    			//i.e the numbers formed by flipping 0 bits of i
	    			for(int j=i;j<=n;j=i|(j+1))
	    			{
	    				if((parent[j]&i)==i)
	    				{
	    					doUnion(parent[j],j);
	    				}
	    				long long root=find(j);
	    				mx=max(mx,size[root]);
	    			}
	    			gmx=max(gmx,mx*i);
	    			
	    			for(int j=i;j<=n;j=i|(j+1))
	    				head[j]=j,size[j]=1;
	    		}

	    	
	    	cout<<gmx<<endl;
	    }











	    
			
		return 0;
	}