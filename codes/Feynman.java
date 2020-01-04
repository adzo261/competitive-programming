package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

public class Feynman {
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        while(true)
        {
            int n=in.nextInt();
            if(n==0)
                break;
            out.println(n*(n+1)*(2*n+1)/6);
        }
    }
}
