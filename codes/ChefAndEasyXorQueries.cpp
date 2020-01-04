	#include <bits/stdc++.h>
	using namespace std;
	#define endl "\n"
	const long long M=1000000007;
	const int N=100010;
	const int SQ=(int)sqrt(N)+100;
	int p[N],a[N];
	int lazy[SQ];
	int mp[SQ][1050000];
	int main() 
	{
		
		ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	    memset(p,0,sizeof(p));
	    memset(a,0,sizeof(a));
	    memset(lazy,0,sizeof(lazy));

    	int n,q;
    	cin>>n>>q;

    	for(int i=0;i<n;i++)
    		cin>>a[i];

    	p[0]=a[0];
    	mp[0][p[0]]++;
    	for(int i=1;i<n;i++)
    	{
    		p[i]=p[i-1]^a[i];
    		mp[i/SQ][p[i]]++;
    	}


    	for(int i=0;i<q;i++)
    	{
    		int s,in,x;
    		cin>>s>>in>>x;
    		in--;
    		if(s==1)
    		{	
    			int temp=in;
    			while(in!=0 && in<n && in%SQ!=0 )
    			{	
    				mp[in/SQ][p[in]]--;
    				p[in]^=(a[temp]^x);
    				mp[in/SQ][p[in]]++;
    				in++;
    			}
    			while((in+SQ)<=n)
    			{	
    				lazy[in/SQ]^=(a[temp]^x);
    				in+=SQ;
    			}
    			while(in<n)
    			{	
    				mp[in/SQ][p[in]]--;
    				p[in]^=(a[temp]^x);
    				mp[in/SQ][p[in]]++;
    				in++;
    			}
    			a[temp]=x;
    		}
    		else
    		{	
    			int ans=0;
    			int i=0;
 				
    			while((i+SQ)<=(in+1))
    			{
    				ans+=mp[i/SQ][x^lazy[i/SQ]];
    				i+=SQ;
    			}
    			while(i<=in)
    			{
    				if((p[i]^lazy[i/SQ])==x)
    					ans++;
    				i++;
    			}
    			cout<<ans<<endl;
    		}
    	}










	    
			
		return 0;
	}