#include <bits/stdc++.h>
using namespace std;
long long M=(long long)(1e9+7);
unordered_map<long long ,long long> f;
 
long long fib(long long n)
{
    if(n<2) return 1;
    if(f.find(n) != f.end()) return f[n];
    f[n] = ((fib((n+1)/2)*fib(n/2))%M + (fib((n-1)/2)*fib((n-2)/2))%M) % M;
    return f[n];
}
int main()
{
 
int t;
cin>>t;
	while(t--)
	{
		long long m,n;
		cin>>m>>n;
		long long a=0,b=0;
		for(int i=0;i<m;i++)
		{	long long p;
			cin>>p;
			a+=p;
		}
		for(int i=0;i<m;i++)
		{	
			long long q;
			cin>>q;
			b+=q;
		}
		a=((a%M)*(m%M))%M;
		b=((b%M)*(m%M))%M;
		if(n==1)
			cout<<a<<endl;
		else if(n==2)
			cout<<b<<endl;
		else
		{	
 
			/*long long ans=0;
			long long pp=a,qq=b;
			for(int i=3;i<=n;i++)
			{
				ans=(ans%M+pp%M+qq%M)%M;
				pp=qq;
				qq=ans;
			}*/
			//cout<<a<<" "<<b<<endl;
			//cout<<fib(0)<<" "<<fib(1)<<" "<<fib(2)<<" "<<fib(3)<<endl;
			n--;
			//cout<<fib(n-2)<<" "<<fib(n-1)<<endl;
			long long ans=(((a*(fib(n-2)%M)%M)+(b*(fib(n-1)%M)%M))%M);
			cout<<ans<<endl;
		}
	}
 
 
 
 
 
 
 
 
 
 
 
 
 
	return 0;	
} 