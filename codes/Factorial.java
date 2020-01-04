package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

public class Factorial {
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int n=in.nextInt();
        int c=0;
        int i=1;
        while(true)
        {
            int t=(int)Math.floor(n/(double)Math.pow(5,i));
            if(t==0)
                break;
            c+=t;
            i++;
        }
        out.println(c);
    }
}
