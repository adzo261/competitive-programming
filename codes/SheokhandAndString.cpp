#include <bits/stdc++.h>
using namespace std;
long long trie[1000010][26];
bool exists[1000010];
long long node;
void insert(string s)
{
	long long tnode=0;
	for(int i=0;i<s.length();i++)
	{		
		if(trie[tnode][s[i]-'a']==0)
			{	

				trie[tnode][s[i]-'a']=node+1;
				node++;
				tnode=node;
				/*if(node==1)
					cout<<trie[node-1][s[i]-'a']<<endl;*/
			}
			else 
			{	
				tnode=trie[tnode][s[i]-'a'];
			}
	}
	//cout<<tnode<<" done true"<<endl;
	exists[tnode]=true;
}

string find(string s)
{	
	string ans;
	long long tnode=0;
	for(int i=0;i<s.length();i++)
	{
		if(trie[tnode][s[i]-'a']!=0) 
			{	
					ans+=s[i];
					tnode=trie[tnode][s[i]-'a'];

			}
			else
			{
				break;
			}
	}
	//cout<<ans<<" "<<s<<endl;
	//cout<<exists[tnode]<<endl;
	//cout<<tnode<<" "<<s<<endl;
	//if(exists[lnode])
	//	return ans;
	while(!exists[tnode])
	{	
		for(int i=0;i<26;i++)
		{
			if(trie[tnode][i]!=0)
			{
				tnode=trie[tnode][i];
				ans+=(char)(i+'a');
				break;
			}
		}
	//	cout<<node<<endl;
	
	}
	return ans;
}
int main()
{
	

long long n;
cin>>n;
string s[n];
for(int i=0;i<n;i++)
{
	cin>>s[i];
}
node=0;
long long q;
cin>>q;
pair<long long ,pair<string,long long> > a[q];
for(int i=0;i<q;i++)
{
	cin>>a[i].first>>a[i].second.first;
	a[i].second.second=i;
}

sort(a,a+q);

string ans[q];
for(int i=0;i<a[0].first;i++)
	insert(s[i]);

ans[a[0].second.second]=find(a[0].second.first);

//cout<<a[0].first<<endl;
//cout<<a[0].second.first<<endl;
//cout<<ans[a[0].second.second]<<endl;
/*for(int i=0;i<=5;i++)
{	cout<<"Node "<<i<<" has ";
	for(int j=0;j<26;j++)
	{
		if(trie[i][j]!=0)
			cout<<(char)(j+'a')<<" "<<trie[i][j]<<" ";
	}
	cout<<endl;
}
*/
for(int i=1;i<q;i++)
{
	if(a[i].first>a[i-1].first)
	{
		for(int j=a[i-1].first;j<a[i].first;j++)
			insert(s[j]);
				/*	for(int i=0;i<=7;i++)
				{	
					cout<<"Node "<<i<<" has ";
					for(int j=0;j<26;j++)
					{
						if(trie[i][j]!=0)
							cout<<(char)(j+'a')<<" "<<trie[i][j]<<" ";
					}
					cout<<endl;
				}*/
		ans[a[i].second.second]=find(a[i].second.first);
	}
	else if(a[i].first==a[i-1].first)
		ans[a[i].second.second]=find(a[i].second.first);
}

for(int i=0;i<q;i++)
	cout<<ans[i]<<endl;

















	return 0;
}