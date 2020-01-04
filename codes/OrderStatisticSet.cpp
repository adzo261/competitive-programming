#include <bits/stdc++.h>
using namespace std;
#define Nm 600100
long long N;
struct Node
{
	long long sum=0;
}tree[Nm];

void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node].sum=0;
	}
	else
	{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
	}
}
void update(int node,int start,int end,int index,int value)
{
	if(start>end)
		return;
	if(start==end && start==index)
	{
		tree[node].sum=value;
		return;
	}
	int mid=(start+end)/2;
	if(index<=mid)
	update(2*node,start,mid,index,value);
	else
	update(2*node+1,mid+1,end,index,value);
	tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
}

long long query(int node,int start,int end,int l,int r)
{	
	
	if(start>r || end<l)
		return 0LL;
	if(l==start && end==r)
	return tree[node].sum;
	else
	{	
		int mid=(start+end)/2;
		if(r<=mid)
			return query(2*node,start,mid,l,r);
		else if(l>mid)
		return query(2*node+1,mid+1,end,l,r);
		
		
		return (query(2*node,start,mid,l,mid)+query(2*node+1,mid+1,end,mid+1,r));
	}
}
int main()
{

	vector<pair<char,long long>> queries;
	vector<long long> ta,a;
	int q;
	cin>>q;

	for(int i=0;i<q;i++)
	{	char temp1;
		cin>>temp1;
		long long temp;
		cin>>temp;
		ta.push_back(temp);
		queries.push_back({temp1,temp});
	}
	sort(ta.begin(),ta.end());
	a.push_back(ta[0]);
	for(int i=1;i<ta.size();i++)
	{
		if(ta[i]!=ta[i-1])
			a.push_back(ta[i]);
	}
	long long N=a.size();
	build(1,0,N-1);

	for(int i=0;i<q;i++)
	{
		int c=queries[i].first;
		long long x=queries[i].second;

		if(c=='I')
		{
			int ind=lower_bound(a.begin(),a.end(),x)-a.begin();
			//cout<<x<<" "<<ind<<" "<<a[ind]<<endl;
			update(1,0,N-1,ind,1);
		}
		else if(c=='D')
		{	
			int ind=lower_bound(a.begin(),a.end(),x)-a.begin();
			//cout<<x<<" "<<ind<<" "<<a[ind]<<endl;
			update(1,0,N-1,ind,0);
		}
		else if(c=='K')
		{	

			long long tempSum=query(1,0,N-1,0,N-1);
			//cout<<x<<" "<<tempSum<<endl;
			if(x>tempSum)
				cout<<"invalid"<<endl;
			else
			{	
				int l=0, r=N-1;

				while(l<r && x>0)
				{
					int mid=(l+r)/2;
					long long sum=query(1,0,N-1,l,mid);
					//cout<<sum<<endl;
					if(sum>=x)
						r=mid;
					else
						l=mid+1,x-=sum;
				}
					//cout<<l<<endl;
					cout<<a[l]<<endl;
			}
		}
		else if(c=='C')
		{
			int ind=lower_bound(a.begin(),a.end(),x)-a.begin();
			//cout<<ind<<endl;
			cout<<query(1,0,N-1,0,ind-1)<<endl;
		}
	}










	return 0;
}