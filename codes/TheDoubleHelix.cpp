#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	while(true)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		vector<long> a;
		for (int i = 0; i < n; ++i)
		{	long k;
			scanf("%ld",&k);
			a.push_back(k);
		}
		scanf("%d",&m);
		vector<long> b;
		for (int i = 0; i < m; ++i)
		{	long k;
			scanf("%ld",&k);
			b.push_back(k);
		}
		long long suma=0,sumb=0,sum=0;
		int i=0,j=0;
		while(true)
		{	if(i>=n && j>=m)
			break;
			if(i<n && j<m && a[i]<b[j])
			{
				suma+=a[i];
				i++;
			}
			else if(i<n && j<m && a[i]>b[j])
			{
				sumb+=b[j];
				j++;
			}
			else if(i<n && j<m && a[i]==b[j])
			{
				sum+=max(suma+a[i],sumb+b[j]);
				suma=sumb=0;
				i++;
				j++;
			}

			if(i>=n)
			{
				while(j<m)
				{
					sumb+=b[j];
					j++;
				}
				sum+=max(suma,sumb);
				break;
			}
			if(j>=m)
			{
				while(i<n)
				{
					suma+=a[i];
					i++;
				}
				sum+=max(suma,sumb);
				break;
			}
			
		}
		printf("%lld\n",sum);

	}
	return 0;
}