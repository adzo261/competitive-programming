#include <bits/stdc++.h>
using namespace std;

long long func(int x,int y)
{
    if(x==0)
    return (y+1)%1000;
    else if(x>0 && y==0)
        return func(x-1,1)%1000;
    else if(x>0 && y>0)
        return func(x-1,func(x,y-1));
}
int main()
{
    
    int x,y;
    cin>>x>>y;
    long long k=func(x,y)%1000;
    if(k<10)
    cout<<"00"<<k<<endl;
    else if(k<100)
    cout<<"0"<<k<<endl;
    else
    cout<<k<<endl;
    
    
    
    
    return 0;
}
