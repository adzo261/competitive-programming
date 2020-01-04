	#include <bits/stdc++.h>
	using namespace std;
	const long long M=1000000007;
	/*About Compare Template parameter:
	A binary predicate that takes two elements (of type T) as arguments and returns a bool.
The expression comp(a,b), where comp is an object of this type and a and b are elements in the container, shall return true if a is considered to go before b in the strict weak ordering the function defines.
The priority_queue uses this function to maintain the elements sorted in a way that preserves heap properties (i.e., that the element popped is the last according to this strict weak ordering).
This can be a function pointer or a function object, and defaults to less<T>, which returns the same as applying the less-than operator (a<b).
*/


//******THIS IS VERY IMPORTANT******//
//that the element popped is the last according to this strict weak ordering).
	int main() 
	{
		
		long long n,m;
		cin>>n>>m;

		long long ball[n+1]={0};
		//lamda with capture by value(=)
	    auto comp=[=](const pair<long long,long long> a,const pair<long long,long long> b)
	    {
	    	 if(a.first==b.first)
	    	{
	    		long long ta=(long long)abs((m+1)/2.0 -a.second);
	    		long long tb=(long long)abs((m+1)/2.0 -b.second);
	    		if(ta==tb)
	    		return (a.second>b.second);
	    		else
	    		return (ta>tb);
	    	}
	    	else
	    		return (a.first>b.first);
	    } ;
	    priority_queue<pair<long long,long long> ,vector<pair<long long,long long>>,decltype(comp)> pq(comp);

	    for(int i=1;i<=m;i++)
	    	pq.push({0,i});

	    for(int i=1;i<=n;i++)
	    {
	    	pair<long long,long long> temp=pq.top();
	    	ball[i]=temp.second;
	    	pq.pop();
	    	pq.push({temp.first+1,temp.second});
	    }

	    for(int i=1;i<=n;i++)
	    	cout<<ball[i]<<endl;






	    
			
		return 0;
	}