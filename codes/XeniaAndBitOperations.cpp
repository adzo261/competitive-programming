#include <bits/stdc++.h>
using namespace std;
#define n 131082
long long a[n];
long long tree[4*n];
void build(long long node,long long start,long long end,long long level)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node]=a[start];
		return;
	}
	long long mid=(start+end)/2;
	build(2*node,start,mid,level+1);
	build(2*node+1,mid+1,end,level+1);

	if(level%2==0)
		tree[node]=tree[2*node]|tree[2*node+1];
	else
		tree[node]=tree[2*node]^tree[2*node+1];

}
void update(long long node,long long start,long long end,long long index,long long value,long long level)
{
	if(start>end)
		return;
	if(start==end && start==index)
	{
		a[start]=value;
		tree[node]=value;
		return;
	}
	else
	{
		long long mid=(start+end)/2;
		if(index<=mid)
			update(2*node,start,mid,index,value,level+1);
		else
			update(2*node+1,mid+1,end,index,value,level+1);
		
		if(level%2==0)
		tree[node]=tree[2*node]|tree[2*node+1];
		else
		tree[node]=tree[2*node]^tree[2*node+1];
	}
}
int main()
{

long long nn,np,m;
cin>>np>>m;
nn=(long long)(pow(2,np));

for(int i=0;i<nn;i++)
	cin>>a[i];
long long level=0;
if(np%2==0)
level=1;
build(1,0,nn-1,level);
/*cout<<tree[1]<<endl;
cout<<tree[2]<<" "<<tree[3]<<endl;
cout<<tree[4]<<" "<<tree[5]<<" "<<tree[6]<<" "<<tree[7]<<endl;*/
while(m--)
{
	long long index,value;
	cin>>index>>value;
	index--;
	update(1,0,nn-1,index,value,level);
	cout<<tree[1]<<endl;
}








	return 0;
}