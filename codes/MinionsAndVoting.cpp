 #include<bits/stdc++.h>
using namespace std;
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long s[n],p[n],l[n]={0},r[n]={0};
		cin>>s[0];
		p[0]=s[0];
		for(int i=1;i<n;i++)
			{
				
				cin>>s[i];
				p[i]=p[i-1]+s[i];
			}
		//long long ans[n]={0};

		for(int i=0;i<n;i++)
		{	
			int a,b,mid,ans;
				if(i!=0)
				{ 		
					a=0,b=i-1,mid=0;
						 ans=-1;
						while(a<=b)
						{
							 mid=(a+b)/2;

							if((p[i-1]-p[mid])<=s[i])
							{
								ans=mid;
								b=mid-1;
							}
							else
								a=mid+1;
						}
						//cout<<ans<<endl;
						if(ans==-1)
							ans=i-1;
						l[ans]++;
						l[i]--;
						/*for(int i=0;i<n;i++)
							cout<<l[i]<<" ";
						cout<<endl;*/
			}

			if(i!=n-1)
			{			
				a=i,b=n-1,mid=0,ans=-1;
						while(a<=b)
						{
							 mid=(a+b)/2;
							 //cout<<a<<" "<<b<<" "<<mid<<endl;
							if((p[mid-1]-p[i])<=s[i])
							{
								
								ans=mid;
								a=mid+1;
							}
							else
								b=mid-1;
						}
						//cout<<ans<<endl;
						if(ans==-1)
							ans=i+1;
						r[ans]++;
						r[i]--;
						/*for(int i=0;i<n;i++)
							cout<<r[i]<<" ";
						cout<<endl;*/
			}
		}
		for(int i=1;i<n;i++)
		{
			l[i]+=l[i-1];
		}
		for(int i=n-2;i>=0;i--)
		{
			r[i]+=r[i+1];
		}
		for(int i=0;i<n;i++)
			cout<<(l[i]+r[i])<<" ";
		cout<<endl;
	}
	return 0;
}