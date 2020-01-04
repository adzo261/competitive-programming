#include <bits/stdc++.h>
using namespace std;
int a[100010];
struct SegTree
{
	int prefixvalue,suffixvalue;
	int prefix,suffix,full;
}tree[4*100010];
void merge(SegTree &parent,SegTree &left,SegTree &right)
{
	parent.prefixvalue=left.prefixvalue;
	parent.prefix=left.prefix;
	parent.suffixvalue=right.suffixvalue;
	parent.suffix=right.suffix;
	if(left.prefixvalue==right.prefixvalue)
		parent.prefix=left.prefix+right.prefix;
	if(left.suffixvalue==right.suffixvalue)
		parent.suffix=left.suffix+right.suffix;
	parent.full=max(left.full,right.full);
	if(left.suffixvalue==right.prefixvalue)
		parent.full=max(parent.full,left.suffix+right.prefix);
}
void build(int node,int start,int end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node].prefixvalue=tree[node].suffixvalue=a[start];
		tree[node].prefix=tree[node].suffix=tree[node].full=1;
	}
	else
	{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		merge(tree[node],tree[2*node],tree[2*node+1]);
	}
}
SegTree query(int node,int start,int end,int l,int r)
{
	SegTree tempTree;
   tempTree.prefix=tempTree.suffix=tempTree.prefixvalue=tempTree.suffixvalue=tempTree.full=0;
    if(start >end || start >r || end < l)
    {
        return tempTree;
    }
	if(l<=start && end<=r)
		 return tree[node];
	else
	{
	int mid=(start+end)/2;
	SegTree left=query(2*node,start,mid,l,r);
	SegTree right=query(2*node+1,mid+1,end,l,r);
	merge(tempTree,left,right);
	return tempTree;
	}
		
}
int main(){
	while(true)
	{
		int n,q;
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&q);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		build(1,0,n-1);
		for (int i = 0; i < q; ++i)
		{	
			int l,r;
			scanf("%d%d",&l,&r);
			
			printf("%d\n",query(1,0,n-1,l-1,r-1).full);
		}


	}
	return 0;
}