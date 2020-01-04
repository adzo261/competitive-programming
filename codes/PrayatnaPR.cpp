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
		int e;
		cin>>e;

		vector<int> g[n];

		for(int i=0;i<e;i++)
		{
			int a,b;
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		bool visited[n]={false};
		int c=0;
		for(int i=0;i<n;i++)
		{
			if(!visited[i])
			{	c++;
				queue<int> q;
				q.push(i);
				visited[i]=true;

				while(!q.empty())
				{
					int temp=q.front();
					q.pop();
						
						for(int j=0;j<g[temp].size();j++)
						{
							if(!visited[g[temp][j]])
							{
								q.push(g[temp][j]);
								visited[g[temp][j]]=true;
							}
						}
				}
			}
		}

		cout<<c<<endl;

	}
















	return 0;
}