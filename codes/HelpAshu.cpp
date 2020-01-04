	#include <bits/stdc++.h>
	using namespace std;
	bool firstTime=false;
	long long getCount(vector<pair<long long ,long long>> &b,int i,int s)
	{
		long long count =0;
		while(i>0)
		{
			if(s==1)
				count+=b[i].first;
			else
				count+=b[i].second;
			i-=i&(-i);
		}
		return count;
	}
	void update(vector<pair<long long ,long long>> &b,long long a[],int n,int i,long long value)
	{	int temp=i-1;
		
		while(i<=n)
		{
			if((a[temp]%2)==(value%2))
			{
				if(a[temp]==value && !firstTime)
					{
						if(value%2==0 )
						b[i].first++;
						else
						b[i].second++;
					}	
			}
			else
			{
				if(value%2==0)
				{
					b[i].first++;
					b[i].second--;
				}
				else
				{

					b[i].first--;
					b[i].second++;
				}
			}
			i+=i&(-i);
		}
		a[temp]=value;
	}
	void build(vector<pair<long long ,long long>> &b,long long a[],int n)
	{	for(int i=1;i<=n;i++)
			b.push_back(make_pair(0,0));
		for(int i=0;i<n;i++)
			update(b,a,n,i+1,a[i]);
		firstTime=true;
	}
	int main()
	{
		int n;
		cin>>n;
		long long a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		vector<pair<long long ,long long>> b;
		b.push_back(make_pair(0,0));
		build(b,a,n);
		//for(int i=1;i<=n;i++)
		//	cout<<b[i].first<<" : "<<b[i].second<<endl;
		int q;
		cin>>q;
		while(q--)
		{

			long long s,x,y;
			cin>>s>>x>>y;
			if(s==0)
			{
				update(b,a,n,x,y);
			}
			else
			{
				cout<<getCount(b,y,s)-getCount(b,x-1,s)<<endl;
			}
		}






		return 0;
	}