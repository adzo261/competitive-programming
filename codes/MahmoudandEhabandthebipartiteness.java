package CP;
import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;


public class TaskB
{   static int colour[];
    static int n;
    static ArrayList<ArrayList<Integer>> g=new ArrayList<>();
    static void bfs()
    {   int source =0;
        Queue<Integer> q=new ArrayDeque<>();
        boolean visited[]=new boolean[n];
        Arrays.fill(visited,false);
        q.add(source);
        visited[source]=true;
        colour[source]=1;
        while ((!q.isEmpty()))
        {
            int t=q.poll();
            for(int i:g.get(t))
            {
                if(!visited[i])
                {
                    if(colour[i]==0)
                        colour[i]=-colour[t];
                    visited[i]=true;
                    q.add(i);
                }
            }
        }
    }
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
         n=in.nextInt();
        for (int i = 0; i < n; i++)
        {
            g.add(new ArrayList<>());
        }
        colour=new int[n];
        Arrays.fill(colour,0);
        for (int i = 0; i < n-1; i++)
        {
            int a=in.nextInt()-1;
            int b=in.nextInt()-1;
            g.get(a).add(b);
            g.get(b).add(a);
        }
        bfs();
        long a=0;
        long b=0;

        for (int i = 0; i < n; i++)
        {   if(colour[i]==1)
            a++;
            if(colour[i]==-1)
                b++;
           /* for (int j = 0; j <n ; j++)
            {     if(i!=j)
                if(!g.get(i).contains(j) && colour[i]!=colour[j])
                    a++;
            }*/
        }
        out.println(a*b-n+1);
    }




}



