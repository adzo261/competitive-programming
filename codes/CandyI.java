package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

public class CandyI
{
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        while(true)
        {
            int n=in.nextInt();
            if(n==-1)
                break;
            int a[]=new int[n];
            int sum=0;
            int avg=0,d=0;
            for (int i = 0; i < n; i++)
            {
                a[i]=in.nextInt();
                sum+=a[i];

            }
            avg=sum/n;
            if(n*avg==sum)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i] < avg)
                    {
                        d += (avg - a[i]);
                    }
                }
                out.println(d);
            }
            else
                out.println(-1);



        }
    }
}
