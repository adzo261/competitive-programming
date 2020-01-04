	#include <bits/stdc++.h>
	using namespace std;
	#define endl "\n"
	const long long M=1000000007;
	const long long N=100010;
	multiset<long long> ug[N];
	vector<pair<long long,long long>> edges;
	map<pair<long long,long long>,long long> mp;
	long long deg[N];
	bool visited[N];
	vector<long long> ans;
	long long n,e;
	void dfs(long long s)
	{	
		visited[s]=true;
		for(auto e:ug[s])
			if(!visited[e])
				dfs(e);
	}

	void heirholzer()
	{	

		    unordered_map<int,int> edge_count;
		    for (int i=0; i<n; i++)
		    {
		        edge_count[i] =ug[i].size();
		    }
		    stack<int> curr_path;
		    vector<int> circuit;
		    curr_path.push(0);
		    int curr_v = 0; 
		    while (!curr_path.empty())
		    {
			        if (edge_count[curr_v])
			        {
			            curr_path.push(curr_v);
			            int next_v = *(ug[curr_v].begin());
			            edge_count[curr_v]--;
			            edge_count[next_v]--;
			            ug[curr_v].erase(ug[curr_v].begin());
			            ug[next_v].erase(ug[next_v].find(curr_v));
			            curr_v = next_v;
			        }
			        else
			        {	
			            circuit.push_back(curr_v);
			            curr_v = curr_path.top();
			            curr_path.pop();
			        }
		    }
		 	
		 	ans.push_back(circuit[circuit.size()-1]);
		    for (int i=circuit.size()-2; i>=1; i--)
		    {
		      ans.push_back(circuit[i]);
		      ans.push_back(circuit[i]);
		    }
		    ans.push_back(circuit[0]);
	}
	int main() 
	{
		
		ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	    cout.tie(NULL);
	    

	    cin>>n>>e;
	   for(int i=0;i<e;i++)
	    {
	    	long long a,b;
	    	cin>>a>>b;
	    	a--,b--;
	    	ug[a].insert(b);
	    	ug[b].insert(a);
	    	deg[a]++,deg[b]++;
	    	edges.push_back({a,b});
	    	mp[{a,b}]=i+1;
	    }

	    dfs(0);

	    bool possible=true;
	    for(int i=0;i<n;i++)
	    	if(!visited[i] || deg[i]&1)
	    	{
	    		possible=false;
	    		break;
	    	}

	    	if(possible)
	    	{
	    		cout<<"YES"<<endl;
	    		heirholzer();
	    		for(int i=1;i<ans.size();i+=2)
	    				{
	    					if(mp[{ans[i-1],ans[i]}]==0)
	    					{
	    						edges[mp[{ans[i],ans[i-1]}]-1]={ans[i-1],ans[i]};
	    					}
	    				}


	    		for(int i=0;i<edges.size();i++)
	    			cout<<edges[i].first+1<<" "<<edges[i].second+1<<endl;
	    	}
	    	else
	    	{
	    		cout<<"NO"<<endl;
	    	}








	    
			
		return 0;
	}