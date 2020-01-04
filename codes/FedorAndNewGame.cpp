#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a;

	for (int i = 0; i <=m ; ++i)
	{
		int t;
		cin>>t;
		a.push_back(t);
	}
	int ans=0;
	for (int i = 0; i <m ; ++i)
	{
		int t=a[i];
		t^=a[m];
	bitset<20> b(t);
		if(b.count()<=k)
			ans++;
	}
	cout<<ans<<"\n";

	return 0;

}