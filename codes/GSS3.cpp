#include <bits/stdc++.h>
using namespace std;
#define MAX_N 50100
int a[MAX_N];
struct SegNode
{
	int prefix,suffix,segsum,bestsum;
} tree[4*MAX_N];
void merge(SegNode &parent,SegNode &leftchild,SegNode &rightchild)
{
	parent.segsum=leftchild.segsum+rightchild.segsum;
	//Sum of all range of parent = sum of range of left child + right child(normal sum of all elements in range)

	parent.prefix=max(leftchild.prefix,leftchild.segsum+rightchild.prefix);
	/*Best prefix sum of parent can lie directly in left child
	or can be in both childs.So for second case full range sum of left + prefix of rightchild*/

	parent.suffix=max(rightchild.suffix,leftchild.suffix+rightchild.segsum);
	/*Best suffix sum of parent can lie directly in right child
	or can be in both childs.So for second case full range sum of right + suffix of rightchild*/
	parent.bestsum=max(leftchild.bestsum,(max(rightchild.bestsum,leftchild.suffix+rightchild.prefix)));
	/*best sum of parent can directly lie in either left child or right child or in both childs.
	When in both childs it will be the best prefix sum of left child+best suffix sum of right child*/
}
void build(int node,int l,int r)
{
	if(l==r) // if range is a single element i.e a leaf node
		tree[node].prefix=tree[node].suffix=tree[node].segsum=tree[node].bestsum=a[l];
	else // if range is not a single element
	{
		int lc=2*node;
		int rc=lc+1;
		int m=(l+r)/2;
		build(lc,l,m);//build left child
		build(rc,m+1,r);//build right child
		merge(tree[node],tree[lc],tree[rc]);
		//Then merge with required logic to get parent
	}
}
void query(SegNode &restree,int node,int start,int end,int l,int r)
{
	if(start==l && end==r)//if range of query is leaf node i.e single element
		restree=tree[node];
	else //if not a leaf node
	{	int lc=2*node;
		int rc=lc+1;
		int mid=(start+end)/2;
		if(r<=mid)
			query(restree,lc,start,mid,l,r);
			//if query range lies completely inside leftchilds range,then query on left child
		else if(l>mid)
			query(restree,rc,mid+1,end,l,r);
		//if query range lies completely inside rightchilds range,then query on right child
		else
			//range lies partially in both childs
		{
			SegNode leftchild,rightchild;
			query(leftchild,lc,start,mid,l,mid);
			//query leftchild partially 
			query(rightchild,rc,mid+1,end,mid+1,r);
			//query rightchild partially
			merge(restree,leftchild,rightchild);
			//merge leftchild and rightchilds result to form parents result
		}

	}
}

void update(int node,int start,int end,int index,int val)
{
	if(start==end && index==start)// if range is a single element i.e a leaf node
	{
		a[index]=val;
		tree[node].prefix=tree[node].suffix=tree[node].segsum=tree[node].bestsum=val;
		return;	
	}
	else
		// if range is not a single element
	{
		int lc=2*node;
		int rc=lc+1;
		int mid=(start+end)/2;
		if(index<=mid)
			update(lc,start,mid,index,val);
			//if index  lies completely inside leftchilds range,then pass update on left child
		else if(index>mid)
			update(rc,mid+1,end,index,val);
		//if index  lies completely inside rightchilds range,then pass update on right child
		
			merge(tree[node],tree[lc],tree[rc]);
			//merge leftchild and rightchilds update to form parents update
	}
	
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//build segment tree here
	build(1,0,n-1);
	scanf("%d",&m);
	
	for(int i=0;i<m;i++)
	{	
		int b,x,y;
		scanf("%d %d %d",&b,&x,&y);
		if(b==0)
			//update a[x] to y
			update(1,0,n-1,x-1,y);
		else if(b==1)
		{//query minimum sum segment in range x to y
			SegNode result;
			query(result,1,0,n-1,x-1,y-1);
			printf("%d\n",result.bestsum);
		}
	}
	return 0;
}
