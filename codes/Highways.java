package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Highways
{   static ArrayList<ArrayList<Edge>> g =new ArrayList<>();
    static class Edge {
      int dest, cost;

        Edge (int dest, int cost)
        {
            this.dest = dest;
            this.cost = cost;
        }
    }
    static class Vertex
    {
        int index,cost;
        Vertex(int index,int cost)
        {
            this.index=index;
            this.cost=cost;
        }
    }
    static long dijkstra(int source,int destination,int n)
    {
        long ans=0;
        int d[]=new int[n];
        Arrays.fill(d,Integer.MAX_VALUE);
        boolean visited[]=new boolean[n];
        Arrays.fill(visited,false);
        PriorityQueue<Vertex> pq=new PriorityQueue<>(new Comparator<Vertex>()
        {
            @Override
            public int compare(Vertex p, Vertex q)
            {
                return p.cost-q.cost;
            }
        });
        pq.offer(new Vertex(source,0));
        d[source]=0;
        visited[source]=true;
        while(!pq.isEmpty())
        {
            Vertex t=pq.poll();
            for(Edge i:g.get(t.index))
            {
                if(!visited[i.dest] && d[i.dest]>t.cost+i.cost)
                {
                    d[i.dest]=t.cost+i.cost;
                    pq.offer(new Vertex(i.dest,d[i.dest]));
                }

            }
        }
        return  d[destination];

    }
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n = in.nextInt();
        int m = in.nextInt();
        for (int i = 0; i < n; i++)
        {
            g.add(new ArrayList<>());
        }
        int source = in.nextInt() - 1;
        int destination = in.nextInt() - 1;
        for (int i = 0; i < m; i++)
        {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int c = in.nextInt();
            g.get(a).add(new Edge(b, c));
            g.get(b).add(new Edge(a, c));
        }
        long ans = dijkstra(source, destination, n);
        if(ans==Integer.MAX_VALUE)
            out.println("NONE");
        else
            out.println(ans);
        g.clear();
    }
}
