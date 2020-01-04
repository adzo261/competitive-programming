package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

public class NumberSteps
{

    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int x=in.nextInt();
        int y=in.nextInt();

            if(x==y)
            {   if(x%2==0)
                out.println(2*x);
                else
                out.println(2*x-1);
            }
            else
            {
                if(x==(y+2))
                {
                   if(x%2!=0 && y%2!=0)
                        out.println(x+y-1);
                   else if(x%2==0 && y%2==0)
                       out.println(x+y);
                }
                else
                    out.println("No Number");
            }
        }
    }

