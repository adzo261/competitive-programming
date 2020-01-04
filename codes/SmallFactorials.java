package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

import java.math.BigInteger;

public class SmallFactorials
{
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {   int n=in.nextInt();

        BigInteger i=BigInteger.ONE;
        for (int j = 1; j <=n; j++)
        {   BigInteger k=new BigInteger(String.valueOf(j));
            i=i.multiply(k);
        }
        out.println(i.toString());
    }
}
