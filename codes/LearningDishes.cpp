	#include <bits/stdc++.h>
	using namespace std;
	#define endl "\n"
	const long long M=1000000007;
	const long long N=1000020;
	const long long LOG_N=21;
	vector<long long> g[N];
	long long up[N][LOG_N];
	long long mx[N],c[N],a[N];
	void dfs(long long p,long long s)
	{

		up[s][0]=p;
		if(s!=0)
		for(int i=1;i<LOG_N;i++)
			{	
				if(up[s][i-1]==-1)
					break;
				up[s][i]=up[up[s][i-1]][i-1];
			}
		if(p==-1)
		{
			mx[s]=a[s],c[s]=1;
		}
		else
		{
			if(mx[p]<a[s])
			mx[s]=a[s],c[s]=c[p]+1;
			else
			mx[s]=mx[p],c[s]=c[p];
		}

		for(auto t:g[s])
			if(t!=p)
				dfs(s,t);
	}
	int main() 
	{
		
		ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	    cout.tie(NULL);
	    

	    int t;
	    cin>>t;

	    while(t--)
	    {	
	    	
	    	long long n;
	    	cin>>n;

	    	for(int i=0;i<n;i++)
	    		g[i].clear();
	    	
	    	fill(mx,mx+n,0);
	    	fill(c,c+n,0);
	    	fill(a,a+n,0);
	    	fill(&up[0][0],&up[0][0]+n*LOG_N,-1);
	    	
	    	for(int i=0;i<n;i++)
	    		cin>>a[i];

	    	for(int i=1;i<n;i++)
	    	{
	    		long long temp;
	    		cin>>temp;
	    		temp--;
	    		g[i].push_back(temp);
	    		g[temp].push_back(i);
	    	}
	    	
	    	dfs(-1,0);

	    	/*for(int i=0;i<n;i++)
	    		cout<<mx[i]<<" "<<c[i]<<endl;
			
	    	for(int i=0;i<n;i++)
	    	{	
	    		cout<<i<<endl;
	    		for(int j=0;j<LOG_N;j++)
	    		{
	    			cout<<j<<" "<<up[i][j]<<" ";
	    		}
	    		cout<<endl;
	    	}*/

	    	long long pr=0;
	    	long long q;
	    	cin>>q;	

	    	while(q--)
	    	{
	    		long long v,w;
	    		cin>>v>>w;
	    		v^=pr;
	    		w^=pr;
	    		v--;

	    		if(mx[v]<=w)
	    		{
	    			pr=0;
	    		}
	    		else if(mx[0]>w)
	    		{
	    			pr=c[v];
	    		}
	    		else
	    		{
		    		long long x=v;
		    		for(int i=LOG_N-1;i>=0;i--)
		    		{
		    			if(up[x][i]!=-1)
		    			{
		    				if(mx[up[x][i]]>w)
		    				{	
		    					x=up[x][i];
		    					
		    				}
		    			}
		    		}
		    		pr=c[v]-c[up[x][0]];
	    		}
	    		
	    		cout<<pr<<endl;
	    	}
	    }








	    
			
		return 0;
	}