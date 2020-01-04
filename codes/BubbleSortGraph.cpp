#include <bits/stdc++.h>
using namespace std;
#define N 100010 
long long tree[4*N];
long long d[N];
long long query(long long node,long long start,long long end,long long l,long long r)
{
	if(start>end || r<start || end<l)
		return 0;
	if(l<=start && end<=r)
		return tree[node];

	long long mid=(start+end)/2;
	return max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}
void update(long long node,long long start,long long end,long long ind,long long value)
{
	if(start>end)
		return;

	if(start==end && start==ind)
	{
		tree[node]=value;
		return;
	}
	long long mid=(start+end)/2;
	if(ind<=mid)
		update(2*node,start,mid,ind,value);
	else
		update(2*node+1,mid+1,end,ind,value);

	tree[node]=max(tree[2*node],tree[2*node+1]);
}
int main()
{

int n;
cin>>n;

long long a[n+1];
for(int i=1;i<=n;i++)
cin>>a[i];
long long ans=0;
for(int i=1;i<=n;i++)
{
	d[a[i]]=query(1,1,n,1,a[i]-1)+1;
	update(1,1,n,a[i],d[a[i]]);
	ans=max(ans,d[a[i]]);
}


cout<<ans<<endl;








	return 0;
}