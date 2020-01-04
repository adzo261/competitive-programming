package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.Arrays;
import java.util.Comparator;

public class LittleDeepuAndArray
{   private static Pair p[];
    private static int n;
    private static int segTree[];
    private static int lazy[];
    static class Pair
    {
        int a;
        int ia;
        Pair(int s,int t)
        {
            a=s;
            ia=t;
        }
    }
    private static void build(int node,int start,int end)
    {   if(start>end)
        return;
        if(start==end)
        {
            segTree[node]=p[start].a;
            return;
        }

            int mid=(start+end)/2;
           build(2*node,start,mid);
           build(2*node+1,mid+1,end);
           segTree[node]=Math.min(segTree[2*node],segTree[2*node+1]);

    }
    private static void update(int node,int start,int end,int l,int r,int x, int value)
    {
        if(start >end || start > r || end < l) return;
        if(lazy[node]!=0)
        {   segTree[node]+=lazy[node];
            if(start!=end)
            {
                lazy[2*node] +=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }

        if (segTree[node] > x)
            {
                segTree[node] += value;
                if(start!=end)
                {
                    lazy[2 * node] += value;
                    lazy[2 * node + 1] += value;
                }
                return;
            }
        if(start==end)
            return;
        int mid=(start+end)/2;
        update(2*node,start,mid,l,r,x,value);
        update(2*node+1,mid+1,end,l,r,x,value);
        segTree[node]=Math.min(segTree[2*node],segTree[2*node+1]);

    }

    private static int query(int node,int start,int end,int l,int r)
    {
        if(start >end || start > r || end < l) return Integer.MAX_VALUE;
        if(lazy[node]!=0)
        {
            segTree[node]+=lazy[node];
            if(start!=end)
            {
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(start>=l && end<=r )
            return segTree[node];

            int mid=(start+end)/2;
            int left= query(2*node,start,mid,l,r);
            int right= query(2*node+1,mid+1,end,l,r);
        return Math.min(left,right);

    }
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {

        int m;
        n=in.nextInt();
        p=new Pair[n];

        for (int i = 0; i <n; i++)
        {
           p[i]=new Pair(in.nextInt(),i);
        }
        m=in.nextInt();
        segTree=new int[4*n];
        lazy=new int[4*n];
        Arrays.fill(lazy,0);
        Arrays.sort(p, new Comparator<Pair>()
        {
            @Override
            public int compare(Pair s, Pair t)
            {
                return (s.a-t.a);
            }
        });
        build(1,0,n-1);

        for (int i = 0; i < m; i++)
        {
            int x=in.nextInt();
            update(1,0,n-1,0,n-1,x,-1);
        }
        for (int i = 0; i < n; i++)
        {
            p[i].a=query(1,0,n-1,i,i);
        }
        Arrays.sort(p, new Comparator<Pair>()
        {
            @Override
            public int compare(Pair s, Pair t)
            {
                return s.ia-t.ia;
            }
        });
        for (int i = 0; i < n; i++)
        {
           out.print(p[i].a+" ");
        }
        out.println();
    }
}
