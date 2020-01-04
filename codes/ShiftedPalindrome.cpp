#include <bits/stdc++.h>
using namespace std;
long long M=1000000007;
long long m=599;
long long power(long long x,long long y)
{	

	x=x%M;
	long long ans=1;
	while(y>0)
	{
		if(y%2!=0)
			ans=((ans%M)*(x%M))%M;
			y/=2;
			x=((x%M)*(x%M))%M;
	}
	return ans%M;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		long long n=s.length();
		long long ans=0;
		s+=s;
		long long nn=s.length();
		long long prefix[nn]={0},suffix[nn]={0};
		prefix[0]=(long long)s[0];
		suffix[0]=(long long)s[nn-1];
		//cout<<power(m,1)<<endl;
		//cout<<prefix[0]<<" "<<suffix[0]<<endl;
		for(int i=1;i<nn;i++)
		{	
			//cout<<power(m,i)<<endl;
			prefix[i]=(prefix[i-1]%M+(((long long)s[i])*(power(m,i)))%M)%M;
		}
		for(int i=nn-2,j=1;i>=1,j<nn;i--,j++)
		{
			suffix[j]=(suffix[j-1]%M+(((long long)s[i])*(power(m,j)))%M)%M;
			//cout<<(((long long)s[i])*(power(m,j)))%M<<endl;
			//cout<<suffix[j]<<endl;
		}
		/*for(int i=0;i<nn;i++)
		{
			cout<<prefix[i]<<" "<<suffix[i]<<endl;
		}*/
		
		for(int i=0;i<=(nn-1-n);i++)
		{
			long long l=i,r=i+n-1;

			long long pa=(l>0)?(((prefix[r]%M)-(prefix[l-1]%M)+M)%M):(prefix[r]%M);
			//pa=((pa%M)*(power(m,abs(nn-r-1-l))%M))%M;
			long long sa=(r<(nn-1))?(((suffix[nn-l-1]%M)-(suffix[nn-r-2]%M)+M)%M):(suffix[nn-l-1]%M);
			//sa=((sa%M)*((power(power(m,abs(nn-r-1-l)),M-2))%M))%M;
			if(l<(nn-1-r))
			{
				pa=((pa%M)*(power(m,abs(nn-r-1-l))%M))%M;
			}
			else
			{
				sa=((sa%M)*(power(m,abs(nn-r-1-l))%M))%M;
			}
			//cout<<pa<<" "<<sa<<endl;
			if(pa==sa)
				ans++;
		}
		/*long long a=prefix[1]%M;
		long long b=(suffix[7]%M-suffix[5]%M+M)%M;
		b=((b%M)*((power(power(m,nn-1-1),M-2))%M))%M;
		cout<<a<<" "<<b<<endl;*/
		cout<<ans<<endl;
	}



	return 0;
}