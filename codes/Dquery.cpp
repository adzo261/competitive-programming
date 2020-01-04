#include <bits/stdc++.h>
using namespace std;
const int MAXN=30010,MAXA=(long long)1e6+10,MAXQ=200000;
int BLOCK,a[MAXN],fq[MAXA],ans[MAXQ],answer=0;

struct query
{
	int index,l,r;
}q[MAXQ];
void add(int index)
{
    fq[a[index]]++;
    if(fq[a[index]]==1) 
    	answer++;
}

void remove(int index)
{
    fq[a[index]]--;
    if(fq[a[index]]==0) 
    	answer--;
}
bool cmp(query a, query b)
{
    int ax = a.l/BLOCK;
    int bx = b.l/BLOCK;
    if (ax != bx)
        return ax < bx;
    return a.r < b.r;
}
int main()
{	  
	ios_base::sync_with_stdio(false);
	int n,m;
	scanf("%d",&n);
	for (int i = 0; i <n; ++i)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for (int i = 0; i <m; ++i)
	{
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].index=i;
		q[i].l--;
		q[i].r--;
	
	}
	BLOCK=(int)(sqrt(n));
	sort(q,q+m,cmp);
	fill_n(fq,MAXA,0);
	int start=q[0].l,end=start;
	fq[a[start]]++;
	answer++;
	for (int i = 0; i <m; ++i)
    {
        while (start < q[i].l)
        {
            remove(start);
            start++;
        }
         while (start > q[i].l)
        {	
          	start--;
           add(start);
           
        }
        while (end < q[i].r)
        {	end++;
           add(end);
           
        }
        while (end > q[i].r)
        {
          remove(end);
          end--;
        }
 		ans[q[i].index] = answer;
    }
    for (int i = 0; i <m; ++i)
    {
    	printf("%d\n",ans[i]);
    }
	return 0;
}