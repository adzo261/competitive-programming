#include <bits/stdc++.h>
using namespace std;
bool bfs(long long source,vector<long long> g[],long long color[])
{
	queue<long long> q;
	q.push(source);
	color[source]=1;

	while(!q.empty() )
	{
		long long temp=q.front();
		q.pop();

		for(int i=0;i<g[temp].size();i++)
		{
			if(color[g[temp][i]]==-1)
			{
				color[g[temp][i]]=1-color[temp];
				q.push(g[temp][i]);
			}
			else if(color[g[temp][i]]==color[temp])
			{
				return false;
				break;
			}
		}
	}

	return true;

}
int main()
{

	long long n,m;
	cin>>n>>m;
	vector<long long> g[n];

	for(int i=0;i<m;i++)
	{
		long long a,b;
		cin>>a>>b;
		a--,b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	long long color[n];
	for(int i=0;i<n;i++)
		color[i]=-1;

	bool possible =true;

	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			possible=bfs(i,g,color);
			if(!possible)
				break;
		}
	}



	if(!possible)
		cout<<-1<<endl;
	else
	{
		vector<long long> f,s;

		for(int i=0;i<n;i++)
		{
			if(color[i]==1)
				f.push_back(i+1);
			else if(color[i]==0)
				s.push_back(i+1);
		}

		cout<<f.size()<<endl;
		for(int i=0;i<f.size();i++)
			cout<<f[i]<<" ";
		cout<<endl;
		cout<<s.size()<<endl;
		for(int i=0;i<s.size();i++)
			cout<<s[i]<<" ";
		cout<<endl;
	}





	return 0;
}