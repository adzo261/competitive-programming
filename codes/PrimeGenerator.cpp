#include<bits/stdc++.h>
using namespace std;


void sieve(long m,long n)
{
bool mark[n+1];
memset(mark,true,sizeof(mark));
bool marked[n-m+1];
memset(marked,true,sizeof(marked));
for(long p=2;p*p<=n;p++)
{
    if(mark[p]==true)
       {
         long k=p*ceil(m/(double)p);
            for(long j=((k<=p) ? (k+=p) : k);j<=n;j+=p)
            {
            marked[j-m]=false;
            mark[j]=false;
            }
        }

}
    if(m==1)
        marked[0]=false;
    for(long i=0;i<sizeof(marked);i++)
    {   if(marked[i]==true)
        cout<<m+i<<"\n"; 
    }

}

int main()
{
ios::sync_with_stdio(false);

long k;
cin>>k;
while(k--)
{
    long n,m;
    cin>>m>>n;
    sieve(m,n);
   
}
return 0;
}
