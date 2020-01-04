	#include <bits/stdc++.h>
	using namespace std;
	#define endl "\n"
	const long long M=1000000007;
	long long m[2010][2010];
	long long d[2010][2010];
	long long n;

	long long head[2010],size[2010];
	struct Edge
	 {
	    long long  u, v, w;
	    Edge(long long a,long long b,long long c)
	    {
	    	u=a;
	    	v=b;
	    	w=c;
	    }
	    bool operator<(Edge const& other) 
	    {
	        return w < other.w;
	    }
	};
	vector<Edge> g;
	vector<Edge> gr[2010];

	long long find(long long x)
	{
		if(x==head[x])
			return x;
		return head[x]=find(head[x]);
	}

	bool doUnion(long long x,long long y)
	{
		long long rootx=find(x);
		long long rooty=find(y);

		if(rootx==rooty)
			return false;

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
		return true;
	}

	void minKruskal()
	{
		sort(g.begin(),g.end());
		for(Edge e:g)
		{	
		
			if(doUnion(e.u,e.v))
			{
				gr[e.u].push_back(e);
				gr[e.v].push_back(Edge(e.v,e.u,e.w));
			}
		}
	}

	void dfs(long long s,long long p,long long u,long long dist)
	{	
		if(d[s][u]==0)
		d[s][u]=d[u][s]=dist;
		for(Edge e:gr[u])
		{	
	
			if(e.v!=p )
			{	
				dfs(s,u,e.v,e.w+dist);
			}
		}
	}
	int main() 
	{
		
		ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	    
    	cin>>n;

    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cin>>m[i][j];
    		}
    	}

    	bool done=true;


    	for(int i=0;i<n;i++)
    		if(m[i][i]!=0)
    		{
    			cout<<"NO"<<endl;
    			return 0;
    		}


    	for(int i=0;i<n;i++)
    		{
    			for(int j=0;j<n;j++)
    			{
    				if(m[i][j]!=m[j][i] || (i!=j && m[i][j]==0))
    				{
    					cout<<"NO"<<endl;
    					return 0;
    				}
    			}
    		}
    	
    		bool visited[n][n]={false};
    		
    		for(int i=0;i<n;i++)
    		{
    			for(int j=0;j<n;j++)
    			{	
    				if(i!=j && !visited[i][j])
    					{
    						g.push_back(Edge(i,j,m[i][j]));
    						visited[i][j]=visited[j][i]=true;
    					}
    			}
    		}


    		for(int i=0;i<n;i++)
    		{
    			head[i]=i;
    			size[i]=1;
    		}

    		minKruskal();

    		for(int i=0;i<n;i++)
    			dfs(i,-1,i,0);

    	
    		for(int i=0;i<n;i++)
    		{
    			for(int j=0;j<n;j++)
    			{
    				if(m[i][j]!=d[i][j])
    				{
    					cout<<"NO"<<endl;
    					return 0;
    				}
    			}
    		}
	    
			cout<<"YES"<<endl;
		return 0;
	}