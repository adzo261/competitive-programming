package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

public class WhatsNext
{
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        while(true)
        {
            int a=in.nextInt();
            int b=in.nextInt();
            int c= in.nextInt();
            if(a==0 && b==0 && c==0)
                break;


            if(c-b==b-a)
            {
                out.println("AP "+(c+c-b));
            }
            else
            {
                out.println("GP "+c*(c/b));
            }
        }
    }
}
