package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.ArrayList;
import java.util.Arrays;

public class TaskB
{

    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n=in.nextInt();
        int t=in.nextInt();
        int a[]=in.nextIntArray(n);
        int c=0;
        long sum=0;
        for (int i = 0; i < n; i++)
        {
            if(sum+a[i]<=t)
            {
                sum+=a[i];
                c++;
            }
            else if(sum!=0)
            {
                sum+=-a[i-c]+a[i];
            }
        }
        out.printLine(c);
    }
}
