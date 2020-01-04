#include <bits/stdc++.h>
using namespace std;
string setUp(string s)
{
	int n=s.length();
	if(n==0)
		return "@$";
	string ans="@";
	for (int i = 0; i < n; ++i)
	{
		ans+="#"+s.substr(i,1);
	}
	ans+="#$";
	return ans;
}
string findLongestPalindrome(string s)
{
	string T=setUp(s);
	long long n=T.length();
	int *P=new int[n+1];
	fill_n(P,n+1,0);
	long long c=0,r=0;
	long long i=1;
	for (i = 1; i < n-1; ++i)
	{
		long long mirror=2*c-i;
		if(i<r)
		{
			if(r-i<P[mirror])
				P[i]=r-i;
			else
				P[i]=P[mirror];
		}
		while(T[i-1-P[i]]==T[i+1+P[i]])
			P[i]++;
		if(i+P[i]>r)
		{
			c=i;
			r=P[i]+i;
		}
	}
	string ans="";
	 i=1;
	for (i = 1; i < n-1; ++i)
	{
		if(P[i]>1)
		{
			ans+="YES";
			break;
		}

	}
	if(i==n-1)
		ans+="NO";
	delete[] P;
	return ans;
	
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		cout<<findLongestPalindrome(s)<<"\n";

	}



	return 0;
}