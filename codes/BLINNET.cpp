#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,pair<long long,long long>>> g;
long long parent[100010];
long long s[100010];
long long n;
long long find(long long e)
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

bool doUnion(long long a,long long b)
{
	long long roota=find(a);
	long long rootb=find(b);
	if(roota==rootb)
		return false;
	if(s[roota]<s[rootb])
	{
		parent[roota]=rootb;
		s[rootb]++;
	}
	else
	{
		parent[rootb]=roota;
		s[roota]++;
	}
	return true;
}	

long long kruskal()
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i<g.size();++i)
    {
    
        x = g[i].second.first;
        y = g[i].second.second;
        cost = g[i].first;
        if( doUnion(x, y))
        {
            minimumCost += cost;
        }    
    }
    return minimumCost;
}
int main()
{
	
	int t;
	cin>>t;

	while(t--)
	{		

		string st;
		cin>>n;	


		g.clear();
		for(int i=0;i<n;i++)
			{	
				parent[i]=i;
				s[i]=1;
				long long m;
				cin>>st>>m;
				while(m--)
				{
					long long temp,b;
					cin>>b>>temp;
					g.push_back({temp,{i,b-1}});
				}
				
			}
		sort(g.begin(),g.end());



		cout<<kruskal()<<endl;
		}


	return 0;
}