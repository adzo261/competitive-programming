package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;
import java.util.*;

public class HorribleQueries
{   static long segTree[],lazy[];
    static void build(int node,int start,int end)
    {
        if(start>end)
            return;;
        if(start==end)
            segTree[node]=0;
        else
        {
            int mid=(start+end)/2;
            build(2*node,start,mid);
            build(2*node+1,mid+1,end);
            segTree[node]=segTree[2*node]+segTree[2*node+1];
        }
    }
    static void update(int node,int start,int end,int l ,int r,long value)
    {

        if(lazy[node]!=0)
        {
            segTree[node]+=(end-start+1)*lazy[node];
            if(start!=end)
            {
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(start>end || start>r || end<l)
            return;
        if(l<=start && end<=r)
        {
            segTree[node]+=(end-start+1)*value;
            if(start!=end)
            {
                lazy[2*node]+=value;
                lazy[2*node+1]+=value;
            }
            return;
        }
        int mid=(start+end)/2;
        update(2*node,start,mid,l,r,value);
        update(2*node+1,mid+1,end,l,r,value);
        segTree[node]=segTree[2*node]+segTree[2*node+1];
    }
    long query(int node,int start,int end,int l,int r)
    {
        if(start>end || start>r ||end<l)
            return 0;
        if(lazy[node]!=0)
        {
            segTree[node]+=(end-start+1)*lazy[node];
            if(start!=end)
            {
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }

        if(l<=start && end<=r)
            return segTree[node];
        int mid=(start+end)/2;
        long q1=query(2*node,start,mid,l,r);
        long q2=query(2*node+1,mid+1,end,l,r);
        return q1+q2;
    }
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n,c;
        n=in.nextInt();
        c=in.nextInt();
        segTree=new long[4*n];
        lazy=new long[4*n];
        Arrays.fill(segTree,0);
        Arrays.fill(lazy,0);
        build(1,0,n-1);
        for (int i = 0; i < c; i++)
        {
            int p,q,r;
            long s;
            p=in.nextInt();
            q=in.nextInt();
            r=in.nextInt();
            if(p==0)
            {   s=in.nextLong();
                update(1,0,n-1,q-1,r-1,s);
            }
            else
                out.println(query(1,0,n-1,q-1,r-1));
        }
    }
}
