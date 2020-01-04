#include <bits/stdc++.h>
using namespace std;

long long find(long long e,long long parent[])
{
	long long root=e;
	//cout<<"In finding";
	while(root!=parent[root])
	{
		root=parent[root];
		//cout<<root<<endl;
	}

	while(e!=root)
	{
		long long p=parent[e];
		parent[e]=root;
		e=p;
	}

	return root;
}

bool doUnion(long long a,long long b,long long s[],long long parent[])
{
	long long roota=find(a,parent);
	long long rootb=find(b,parent);
	//cout<<roota<<" "<<rootb<<endl;
	if(roota==rootb)
		return false;
	if(s[roota]<s[rootb])
	{
		parent[roota]=rootb;
	}
	else if(s[rootb]<s[roota])
	{
		parent[rootb]=roota;
	}
	return true;
}	
int main()
{
int t;
cin>>t;

	while(t--)
	{	
		long long n;
		cin>>n;
		long long s[n];
     long long parent[n];
		for(int i=0;i<n;i++)
			cin>>s[i];
		//cout<<nn<<endl;
		for(int i=0;i<n;i++)
			parent[i]=i;

		/*for(int i=0;i<nn;i++)
			cout<<parent[i]<<" ";*/
		long long q;
		cin>>q;
		while(q--)
		{

			long long c,x,y;
			cin>>c>>x;
			x--;
			if(c==0)
			{
				cin>>y;
				y--;
				bool status=doUnion(x,y,s,parent);
				if(!status)
					cout<<"Invalid query!"<<endl;
			}
			else
			{
				cout<<(find(x,parent)+1)<<endl;
			}
		}
	}










	return 0;
}