#include <bits/stdc++.h>
using namespace std;


vector<long long> euler;
long long tree[8*1100];
long long height[1100];
long long first[1100];
bool visited[1100];
vector<long long> g[1100];
long long n;

void dfs(long long source,long long h)
{
	visited[source]=true;
	first[source]=euler.size();
	euler.push_back(source);
	height[source]=h;
	for(auto dest:g[source])
	{
		if(!visited[dest])
		{
			dfs(dest,h+1);
			euler.push_back(source);
		}
	}

}
void build(long long node,long long start,long long end)
{
	if(start==end)
	{
		tree[node]=euler[start];
		return;
	}
	long long mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	if(height[tree[2*node]]<height[tree[2*node+1]])
		tree[node]=tree[2*node];
	else
		tree[node]=tree[2*node+1];
}
long long minimum(long long node,long long start,long long end,long long l,long long r)
{
	if(start>end || start>r || end<l)
		return 10000000000;

	if(l<=start && end<=r)
		return tree[node];

	long long mid=(start+end)>>1;
	long long a=minimum(2*node,start,mid,l,r);
	long long b=minimum(2*node+1,mid+1,end,l,r);
	if(a==10000000000)
		return b;
	else if(b==10000000000)
		return a;
	else
	if(height[a]<height[b])
		return a;
	else
		return b;
}
long long lcs(long long a,long long b)
{
	a=first[a],b=first[b];
	if(a>b)
		swap(a,b);
	return minimum(1,0,euler.size()-1,a,b);

}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{	
		cin>>n;
		for(int i=0;i<n;i++)
		{
			g[i].clear();
		}
		memset(first,0,sizeof(first));
		memset(height,0,sizeof(height));
		memset(visited,0,sizeof(visited));
		memset(tree,0,sizeof(tree));
		euler.clear();
		for(int i=0;i<n;i++)
		{
			int m;
			cin>>m;
			for(int j=0;j<m;j++)
			{
				long long temp;
				cin>>temp;
				temp--;
				g[i].push_back(temp);
				g[temp].push_back(i);
			}
		}
		dfs(0,1);
		
		long long q;
		cin>>q;
		cout<<"Case "<<(i+1)<<":"<<endl;
		build(1,0,euler.size()-1);
	
		for(int i=0;i<q;i++)
		{
	
			long long ta,tb;
			cin>>ta>>tb;
			ta--,tb--;
			cout<<(lcs(ta,tb)+1)<<endl;
		}

	}

	return 0;
}