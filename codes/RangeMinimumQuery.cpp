#include <bits/stdc++.h>
using namespace std;
int query(int *block,int *a,int l,int r,int rn)
{
	int ans=INT_MAX;
	while(l<=r && l%rn!=0)
	{
		ans=min(ans,a[l++]);
	}
	while(l+rn<=r)
	{
		int bid=l/rn;
		ans=min(ans,block[bid]);
		l+=rn;
	}
	while(l<=r)
	{
		ans=min(ans,a[l++]);
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int rn=sqrt(n);
	int block[rn];
	for(int i=0;i<rn;i++)
		block[i]=INT_MAX;
	
	int a[n];
	int j=-1;
	for(int i=0;i<n;i++)
		{	if(i%rn==0)
				j++;
				
				cin>>a[i];
				block[j]=min(block[j],a[i]);
				
		}

	int q;
	cin>>q;
	while(q--)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(block,a,l,r,rn)<<endl;
		}





	return 0;
}