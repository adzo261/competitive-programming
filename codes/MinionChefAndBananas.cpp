#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long h,a[n];
		cin>>h;
		long long mx=-1000000000;
		for(int i=0;i<n;i++)
			cin>>a[i],mx=max(mx,a[i]);
		long long l=1,r=mx;
		long long i=0;
		long long ans=-1;
		
			while(l<=r)
			{	
				 i=(l+r)/2;
				//cout<<l<<" "<<i<<" "<<r<<endl;
				long long temp=0;
				for(int j=0;j<n;j++)
				{
					temp+=a[j]/i;
					if(a[j]%i!=0)
						temp++;
				}
				//cout<<temp<<endl;
				if(temp==h)
				{	//cout<<temp<<endl;
					r=i-1;
					ans=i;
				}
				else if(temp<h)
				{
					r=i-1;
				}
				else
				{
					l=i+1;
				}
 
			}
			//cout<<ans<<endl;
			//cout<<l<<" "<<r<<endl;
			long long tl=0,tr=0,ta=0;
			for(int j=0;j<n;j++)
			{
				tl+=ceil(((long double)a[j])/l);
				if(r!=0)
				tr+=ceil(((long double)a[j])/r);
				if(ans!=-1)
				ta+=ceil(((long double)a[j])/ans);
			}
			
				if(tr<=h && tr>0)
					cout<<r<<endl;
				else if(ta<=h && ta>0)
					cout<<ans<<endl;
				else if(tl<=h)
					cout<<l<<endl;
			
			
	}
 
 
 return 0;
}
 
 
