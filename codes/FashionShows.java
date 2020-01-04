package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.util.Arrays;

public class FashionShows
{
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n=in.nextInt();
        int a[]=in.nextIntArray(n);
        int b[]=in.nextIntArray(n);
        Arrays.sort(a);
        Arrays.sort(b);
        long ans=0;
        for (int i = 0; i < n; i++)
        {
            ans+=a[i]*b[i];
        }
        out.println(ans);
    }
}
