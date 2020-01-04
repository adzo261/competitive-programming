#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	vector<long long> a;
	for (int i = 0; i < m; ++i)
	{
		long long t;
		cin>>t;
		a.push_back(t);
	}
	long long ans=a[0]-1;
	for (int i = 1; i < m; ++i)
	{
		if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
		else if(a[i]<a[i-1])
			ans+=n-(a[i-1]-a[i]);
	}
	cout<<ans<<"\n";

	return 0;
}