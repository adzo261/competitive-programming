#include <bits/stdc++.h>
using namespace std;


vector<long long> euler;
long long tree[8*200010];
long long height[200010];
long long first[200010];
bool visited[200010];
vector<long long> g[200010];
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
		
		cin>>n;
		for(int i=0;i<n-1;i++)
		{
			long long ta,tb;
			cin>>ta>>tb;
			ta--,tb--;
			g[ta].push_back(tb);
			g[tb].push_back(ta);
		}

			memset(first,0,sizeof(first));
			memset(height,0,sizeof(height));
			memset(visited,0,sizeof(visited));
			memset(tree,0,sizeof(tree));
			euler.clear();
			dfs(0,1);
			build(1,0,euler.size()-1);
		long long q;
		cin>>q;
		while(q--)
		{
			
			long long r,u,v;
			cin>>r>>u>>v;
			r--,u--,v--;
			/*Let w be the lca of u and v in 1 rooted tree
				if w is in the subtree of root r, then w is answer
				i.e case when two of lca(u,r)=r,lca(v,r)=r,lca(u,v)=w are equal and one is different w.r.t root 1

				if r is in the subtree of w and u and v are also in the subtree of w but not in subtree of r,then w is answer
				i.e case when all of the three,lca(u,r)=w,lca(v,r)=w,lca(u,v)=w are equal w.r.t root 1 

				if r is in the subtree of u/v,then r is the answer
				i.e case when two of lca(u,r)=u/v,lca(v,r)=r,lca(u,v)=u/v are equal and one is different w.r.t root 1

				Summary:
				find lca(u,v),lca(u,r),lca(v,r)
				and the odd man out is answer.
				If no odd man out exists, the common answer is itself the answer.*/

			long long a,b,c;
			a=lcs(u,v),b=lcs(u,r),c=lcs(v,r);
			if(a==b && b==c)
				cout<<(a+1)<<endl;
			else if(a==b)
				cout<<(c+1)<<endl;
			else if(b==c)
				cout<<(a+1)<<endl;
			else
				cout<<(b+1)<<endl;
		}


	return 0;
}