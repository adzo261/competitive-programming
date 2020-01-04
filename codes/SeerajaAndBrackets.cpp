	#include <bits/stdc++.h>
	using namespace std;
	const long long M=1000000007;
	const long long N=1000065;
	string s;
	struct Node
	{
		long long uopen,uclose;
		long long mbrac;
		Node()
		{

		}
		Node(long long uopen,long long uclose,long long mbrac)
		{
			this->uopen=uopen;
			this->uclose=uclose;
			this->mbrac=mbrac;
		}
	} tree[4*N];
	


	void build(long long node,long long start,long long end)
	{
		if(start>end)
			return;

		if(start==end)
		{
			if(s[start]=='(')
				tree[node]=Node(1,0,0);
			else
				tree[node]=Node(0,1,0);
			//cout<<start<<endl;
			//cout<<tree[node].uopen<<" "<<tree[node].uclose<<" "<<tree[node].mbrac<<endl;

			return ;
		}

		long long mid=(start+end)>>1;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].uopen=tree[2*node].uopen+tree[2*node+1].uopen;
		tree[node].uclose=tree[2*node].uclose+tree[2*node+1].uclose;
		tree[node].mbrac=tree[2*node].mbrac+tree[2*node+1].mbrac+min(tree[2*node].uopen,tree[2*node+1].uclose);
		if(min(tree[2*node].uopen,tree[2*node+1].uclose)>0)
			{
				tree[node].uopen-=min(tree[2*node].uopen,tree[2*node+1].uclose);
				tree[node].uclose-=min(tree[2*node].uopen,tree[2*node+1].uclose);
			}
	}

	Node query(long long node,long long start,long long end,long long l,long long r)
	{
		if(start>end || start>r || end<l)
			return Node(0,0,0);

		if(l<=start && end<=r)
			return tree[node];

		long long mid=(start+end)>>1;
		Node ta=query(2*node,start,mid,l,r);
		Node tb=query(2*node+1,mid+1,end,l,r);
		Node tans;

		tans.uopen=ta.uopen+tb.uopen;
		tans.uclose=ta.uclose+tb.uclose;
		tans.mbrac=ta.mbrac+tb.mbrac+min(ta.uopen,tb.uclose);
		if(min(ta.uopen,tb.uclose)>0)
			{
				tans.uopen-=min(ta.uopen,tb.uclose);
				tans.uclose-=min(ta.uopen,tb.uclose);
			}
		return tans;

	}
	int main() 
	{
		
	    cin>>s;

	    long long n=s.length();

	    long long m;
	    cin>>m;
	    build(1,0,n-1);
	    while(m--)
	    {
	    	long long l,r;
	    	cin>>l>>r;
	    	l--,r--;
	    	Node ans=query(1,0,n-1,l,r);
	    	cout<<2*ans.mbrac<<endl;
	    }









	    
			
		return 0;
	}