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

		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
	
			int ind=-1;
			for(int i=n-1;i>=1;i--)
			{	
				bool toBreak=false;
				if(a[i]>a[i-1])
				{
					
					for(int j=n-1;j>=i;j--)
					{
						if(a[j]>a[i-1])
						{
							int temp=a[i-1];
							a[i-1]=a[j];
							a[j]=temp;
							ind=i;
							toBreak=true;
							break;
						}
					}
				}
				if(toBreak)
					break;
			}
			if(ind==(-1))
				cout<<ind<<endl;
			else
			{
				 sort(a+ind,a+n);
				for(int i=0;i<n;i++)
					cout<<a[i];
				cout<<endl;
			}
		
	}






	return 0;
}