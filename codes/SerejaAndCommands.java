package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;


public class SerejaAndCommands
{   static long[] segTree,lazy;
    static long M = (long) 1e9 + 7;
    void build(long a[],int node,int start,int end)
    {
        if(start == end)
        {
            segTree[node]=a[start];
            return;
        }
        int mid=(start+end)/2;
        build(a,2*node,start,mid);
        build(a,2*node+1,mid+1,end);
        segTree[node]=(segTree[2*node]%M+segTree[2*node+1]%M)%M;
    }
    long query(int node,int start,int end,int l,int r)
    {

        if(start>end || start>r || end<l)
            return 0;
        if(lazy[node]!=0)
        {
            segTree[node]=(segTree[node]%M+((end-start+1)*lazy[node])%M)%M;
            if(start!=end)
            {
                lazy[2*node]=(lazy[2*node]%M+lazy[node]%M)%M;
                lazy[2*node+1]=(lazy[2*node+1]%M+lazy[node]%M)%M;
            }
            lazy[node]=0;
        }


            if(l<=start && r>=end)
                return segTree[node];
            int mid=(start+end)/2;
            long p=query(2*node,start,mid,l,r);
            long q=query(2*node+1,mid+1,end,l,r);
            return (p%M+q%M)%M;
    }
    void update(int node,int start,int end,int l,int r,long value)
        {   if(start>end || start>r || end<l)
            return;
            if(lazy[node]!=0)
            {
                segTree[node]=(segTree[node]%M+((end-start+1)*lazy[node])%M)%M;
                if(start!=end)
                {
                    lazy[2*node]=(lazy[2*node]%M+lazy[node]%M)%M;
                    lazy[2*node+1]=(lazy[2*node+1]%M+lazy[node]%M)%M;
                }
                lazy[node]=0;
            }


            if(l<=start && r>=end)
            {
                segTree[node]=(segTree[node]%M+((end-start+1)*value)%M)%M;
                if(start!=end)
                {
                    lazy[2*node]=(lazy[2*node]%M+value%M)%M;
                    lazy[2*node+1]=(lazy[2*node+1]%M+value%M)%M;
                }
                return;
            }
            int mid=(start+end)/2;
            update(2*node,start,mid,l,r,value);
            update(2*node+1,mid+1,end,l,r,value);
            segTree[node]=(segTree[2*node]%M+segTree[2*node+1]%M)%M;

        }
    static class Triplet
    {   int type;
        int first,second;

        Triplet(int type,int first,int second)
        {   this.type=type;

            this.first=first;
            this.second=second;

        }
    }

    public void solve(int testNumber, InputReader in, OutputWriter out)
    {

        int n, m;
        n = in.nextInt();
        m = in.nextInt();
        segTree=new long[4*Math.max(n,m)];
        lazy=new long[4*Math.max(n,m)];
        ArrayList<Triplet> s = new ArrayList<>();
        long[] c = new long[m];
        long[] a=new long[n];
        Arrays.fill(a,0);
        for (int i = 0; i < m; i++)
        {
            int t = in.nextInt();
            int l = in.nextInt()-1;
            int r = in.nextInt()-1;
            s.add(new Triplet(t, l, r));
            c[i]=1;
        }
        build(c,1,0,m-1);
        for (int i = m-1; i >=0; i--)
        {
            if(s.get(i).type==2)
            {
                long q=query(1,0,m-1,i,i);
                update(1,0,m-1,s.get(i).first,s.get(i).second,q);
            }
        }
        for (int i = 0; i < m; i++)
        {
            c[i]=query(1,0,m-1,i,i);
        }
        Arrays.fill(lazy,0);
        build(a,1,0,n-1);
        for (int i = 0; i < m; i++)
        {
            if(s.get(i).type==1)
            {
                update(1,0,n-1,s.get(i).first,s.get(i).second,c[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            out.print(query(1,0,n-1,i,i)+"  ");
        }
        out.println();
    }

    }

