	#include <bits/stdc++.h>
	using namespace std;
	const long long M=1000000007;
	//Code follows Pseudo code from Cormen on KMP -Page:1005
	void computeLPSArray(string pattern,int lps[])
	{	
		/*lps array stores  the length of proper prefix which is also a proper 
		suffix of string pattern 1.....i*/
		lps[1]=0;
		int k=0; //Denotes number of characters matched
		for(int i=2;i<pattern.length();i++)
		{
			while(k>0 && pattern[k+1]!=pattern[i])
				k=lps[k];

			if(pattern[k+1]==pattern[i])
				k++;

			lps[i]=k;
		}

	}
	int KMPMatching(string text,string pattern,int lps[])
	{	
		int prefix=0;
		int ans=-1;
		int k=0; //Denotes number of characters matched

		for(int i=1;i<text.length();i++)
		{
			while(k>0 && pattern[k+1]!=text[i])
				k=lps[k];

			//This is problem specific
			if(pattern[k+1]==text[i])
			{
						k++;
					if(prefix<k)
					{
						prefix=k;
						ans=i-prefix;
					}
			}

			
			// Standard KMP part is as follows
			/*
				if(pattern[k+1]==text[i])
				{
					k++;
				}
				if(k==(pattern.length()-1))
					k=lps[k]; // Pattern full matched,now find next shift required to continue matching
			*/
		}
		return ((ans==-1)?0:ans);
	}
	int main() 
	{
		
	    int n;
	    cin>>n;
	    string a,b;
	    cin>>a>>b;
	    a="#"+a;
	    b="#"+b+b;

	    int lps[n+1]={0};

	    computeLPSArray(a,lps);
	    
	    cout<<KMPMatching(b,a,lps)<<endl;











	    
			
		return 0;
	}