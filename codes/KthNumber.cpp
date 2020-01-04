#include<bits/stdc++.h>
using namespace std;
const long long N=100010;
long long a[N];
vector<long long> segTree[4*N];
void build(int node,int start,int end)
{
	if(start>end)
		return;
	if(start==end)
	{
		segTree[node].push_back(a[start]);
		return;
	}
	int mid=(start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	vector<long long> left=segTree[2*node];
	vector<long long>  right=segTree[2*node+1];
	merge(left.begin(),left.end(),right.begin(),right.end(),back_inserter(segTree[node]));
}

long long query(int node,int start,int end,int l,int r,int v)
{	
	
	if(start>end || start>r || end<l)
		return 0;
	if(l<=start && end<=r)
	{	
		return(upper_bound(segTree[node].begin(),segTree[node].end(),a[v])-segTree[node].begin());
		
	}
	int mid=(start+end)/2;
	return(query(2*node,start,mid,l,r,v)+query(2*node+1,mid+1,end,l,r,v));
	
}
int main()
{	 
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	build(1,0,n-1);
	sort(a,a+n);
	while(m--)
	{
		int i,j,k;
		scanf("%d %d %d",&i,&j,&k);
		
		int l=0,r=n-1,ans=-1;
		
		while(l<=r)
		{	

			int mid=(l+r)/2;
			int kk=query(1,0,n-1,i-1,j-1,mid);
			//cout<<kk<<" "<<l<<" "<<r<<" "<<a[mid]<<endl;
			if(kk>=k)
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		
		}
		//cout<<ans<<endl;
		 printf("%lld\n",a[ans]);
	}
	return 0;
}