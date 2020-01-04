package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.ArrayList;
import java.util.Comparator;

public class LearningGraph
{   private ArrayList<ArrayList<Pair>> g=new ArrayList<>();
    private static class Pair
    {
        int t,value;
        Pair(int t,int value)
        {
            this.t=t;
            this.value=value;
        }
    }
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n=in.nextInt();
        int m=in.nextInt();
        int k=in.nextInt();
        int values[]=new int[n];
        for (int i = 0; i <n; i++)
        {
            values[i]=in.nextInt();
        }
        for (int i = 0; i <n ; i++)
        {
            g.add(new ArrayList<Pair>());

        }
        for (int i = 0; i <m; i++)
        {
            int a=in.nextInt();
            int b=in.nextInt();
            g.get(a-1).add(new Pair(b-1,values[b-1]));
            g.get(b-1).add(new Pair(a-1,values[a-1]));

        }
        for (int i = 0; i < n; i++)
        {
            g.get(i).sort(new Comparator<Pair>()
            {
                @Override
                public int compare(Pair a, Pair b)
                {
                    if(a.value==b.value)
                        return a.t<b.t?1:-1;
                    else
                        return a.value<b.value?1:-1;


                }
            });
        }

        for (int i = 0; i < n; i++)
        {   if(k>g.get(i).size())
            out.println(-1);
            else
            out.println(g.get(i).get(k-1).t+1);
        }

    }
}
