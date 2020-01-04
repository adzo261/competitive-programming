#include <bits/stdc++.h>
using namespace std;
long long modularExpo(long long a,long long b)
{

	long long ans=1;
	a%=10;

	while(b>0)
	{
		if(b%2!=0)
			ans=(ans*a)%10;
		b/=2;
		a=(a*a)%10;

	}
	return ans;
}
int main()
{
		long  t;
		cin>>t;
		while(t--)
		{
			long long a,b;
			cin>>a>>b;
			cout<<modularExpo(a,b)<<endl;
		}

	return 0;
}
