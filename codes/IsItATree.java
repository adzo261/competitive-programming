package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;

public class IsItATree
{
    static ArrayList<ArrayList<Integer>> g=new ArrayList<>();
    static boolean visited[];
    static void dfs()
    {

        Stack<Integer> s=new Stack<>();
        s.push(0);
        visited[0]=true;
        while(!s.isEmpty())
        {
            int t=s.pop();
            for(int i:g.get(t))
            {
                if(!visited[i])
                {
                    s.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n=in.nextInt();
        int m=in.nextInt();
        visited=new boolean[n];
        Arrays.fill(visited,false);
        for (int i = 0; i < n; i++)
        {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++)
        {
            int a=in.nextInt()-1;
            int b=in.nextInt()-1;
            g.get(a).add(b);
            g.get(b).add(a);
        }
        String r="YES";
        dfs();
        for (int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                r="NO";
                break;
            }
        }
        if(r.equals("YES") )
        {   if(m!=n-1)
            r="NO";
        }
        out.println(r);

    }
}
