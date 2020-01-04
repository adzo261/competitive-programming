#include <bits/stdc++.h>
using namespace std;
char s[5005];
int main()
{
while(true)
{	
	scanf("%s",s);
	if(s[0]=='0')
		break;
	string st=s;
	
	array<unsigned long long,5005> dp={0};

	dp[0]=1;
	
	for (int i = 1; i < strlen(s); ++i)
	{	if(s[i]-'0')
		dp[i]=dp[i-1];
		int no=stoi(st.substr(i-1,2));
		if(no>=10 && no<=26)
			dp[i]+=dp[i-2<0?0:i-2];

	}
	printf("%lld\n",dp[strlen(s)-1]);

	
}



	return 0;
}