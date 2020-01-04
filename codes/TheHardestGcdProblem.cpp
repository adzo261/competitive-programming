#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		long long a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		bool possible=false;
		long long g=a[0];
		for(int i=1;i<n;i++)
			g=__gcd(g,a[i]);

		if(g==1 || g<=k ||(n==1 && g%k==0))
			possible=true;
		if(!possible)
		{		bool megaPossible=false;
				while (g%2 == 0)
		    	{	
		    		if(2>k)
		    			{
		    				megaPossible=true;
		    				break;
		    			}
		        	g/=2;
		    	}

		 
		    for (int i = 3; i*i<=g; i +=2)
		    {	bool done=false;
		        while (g%i == 0)
		        {	
		        	if(i>k)
		    			{
		    					megaPossible=true;
		    				done=true;
		    				break;
		    			}
		            g/=i;
		        }
		        if(done)
		        	break;
		    }
		    if (g > 2)
		        {
		        	if(g>k)
		    			{
		    					megaPossible=true;
		    			}
		        }
		        if(!megaPossible)
		        	possible=true;
		}
		//cout<<possible<<endl;
		if(possible)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}










	return 0;
}