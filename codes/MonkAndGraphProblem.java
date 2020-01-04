package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.Queue;
import java.util.ArrayDeque;
import java.util.ArrayList;

public class MonkAndGraphProblem
{
    private ArrayList<ArrayList<Integer>> g=new ArrayList<>();
    private boolean[] visited;
    private int bfs(int source)
    {
        int edges=0;
        Queue<Integer> q=new ArrayDeque<>();
        q.add(source);
        visited[source]=true;
        while(!q.isEmpty())
        {
            int t=q.poll();
            for (int n:g.get(t))
            {    edges++;
                if(!visited[n])
                {
                    visited[n]=true;
                    q.add(n);

                }
            }
        }
        return  edges/2;
    }
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n=in.nextInt();
        int m=in.nextInt();
        for (int i = 0; i < n; i++)
        {
            g.add(new ArrayList<>());
        }
        visited=new boolean[n];
        for (int i = 0; i < m; i++)
        {
            int a=in.nextInt();
            int b=in.nextInt();
            g.get(a-1).add(b-1);
            g.get(b-1).add(a-1);
        }
        int ans=Integer.MIN_VALUE;
        for (int i = 0; i < n; i++)
        {
            if(!visited[i])
                ans=Math.max(ans,bfs(i));
        }
        out.println(ans);
    }

}
