#include <bits/stdc++.h>
using namespace std;
#define N 100010
int a[N];
long long ans;
void merge(int start,int mid,int end,int a[])
{

	queue<int> p,q,r;
	for(int i=start;i<=mid;i++)
		p.push(a[i]);
	for(int i=mid+1;i<=end;i++)
		q.push(a[i]);

	while(!p.empty() && !q.empty())
	{
			if(p.front()<q.front())
			{
				r.push(p.front());
				ans+=(p.front())*(long long)q.size();
				p.pop();
			}
			else
			{
				r.push(q.front());
				q.pop();
			}
	}
	while(!p.empty())
	{
		r.push(p.front());
		p.pop();
	}

	while(!q.empty())
	{
		r.push(q.front());
		q.pop();
	}

	int i=start;
	while(!r.empty())
	{
		a[i++]=r.front();
		r.pop();
	}

}
void mergeSort(int start,int end ,int a[])
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergeSort(start,mid,a);
		mergeSort(mid+1,end,a);
		merge(start,mid,end,a);
	}
}
int main()
{

int t;
cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		ans=0;
		mergeSort(0,n-1,a);
		cout<<ans<<endl;
	}










	return 0;
}