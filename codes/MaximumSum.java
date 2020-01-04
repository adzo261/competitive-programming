package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.Arrays;

public class MaximumSum
{   static long a[];
    static class SegNode
    {
        long first,second;
        SegNode(long first,long second)
        {
            this.first=first;
            this.second=second;
        }
    }
    static SegNode tree[];
    static SegNode merge(SegNode left,SegNode right)
    {
        SegNode parent=new SegNode(0,0);
        long t[]={left.first,left.second,right.first, right.second};
        Arrays.sort(t);
        parent.first=t[2];
        parent.second=t[3];
        return parent;
    }
    void build(int node,int start, int end)
    {
        if(start>end)
            return;
            if(start==end)
            {
                tree[node]=new SegNode(a[start],0);
            }
            else
            {
                int mid=(start+end)/2;
                build(2*node,start,mid);
                build(2*node+1,mid+1,end);
                tree[node]=merge(tree[2*node],tree[2*node+1]);
            }
    }
    void update(int node,int start,int end,int i,int value)
    {
        if(start==end)
        {
            a[i]=value;
            tree[node]=new SegNode(value,0);
        }
        else
        {
            int mid=(start+end)/2;
            if(start<=i && i<=mid)
                update(2*node,start,mid,i,value);
            else
                update(2*node+1,mid+1,end,i,value);
            tree[node]=merge(tree[2*node],tree[2*node+1]);
        }

    }
    SegNode query(int node,int start,int end,int l,int r)
    {   SegNode result=new SegNode(0,0);
        if(start>end || start>r || end<l)
            return result;
        if(l<=start && end<=r)
        {
            result= tree[node];
        }
        else
        {
            int mid = (start + end) / 2;
            result = merge(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
        }
        return result;
    }
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n=in.nextInt();
        a=new long[n];
        tree=new SegNode[4*n];
        for (int i = 0; i < n; i++)
        {
            a[i]=in.nextLong();
        }
        build(1,0,n-1);
        int q=in.nextInt();
        for (int i = 0; i < q; i++)
        {
            char c=in.nextCharacter();
            int l=in.nextInt();
            int r=in.nextInt();
            if(c=='U')
            {
                update(1,0,n-1,l-1,r);
            }
            else
            {
                SegNode k=query(1,0,n-1,l-1,r-1);
                out.println(k.first+k.second);
            }
        }

    }
}
