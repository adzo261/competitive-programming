#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a;
		cin>>a;
		stack<char> s;
		for (int i = 0; i <a.size() ; i++)
		{
			if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^')
				s.push(a[i]);
			if(a[i]>='a' && a[i] <='z')
				cout<<a[i];
			if(a[i]==')')
			{
				cout<<s.top();
				s.pop();
			}
		}
		while(!s.empty())
		{
			cout<<s.top();
			s.pop();
		}
		cout<<endl;
	}
	return 0;
}