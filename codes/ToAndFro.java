package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

public class ToAndFro
{
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        while(true)
        {
            int n=in.nextInt();
            if(n==0)
                break;
            String s=in.nextString();

           char a[][]=new char[s.length()/n][n];
           int k=0;int status=1;
            for (int i = 0; i < (s.length()/n); i++)
            {   if(status==1)
                {
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = s.charAt(k++);
                }
                status = -1;
                }
                else
                {
                for (int j = n - 1; j >= 0; j--)
                {
                    a[i][j] = s.charAt(k++);
                }
                status = 1;
                }

            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <(s.length()/n) ; j++)
                {
                    out.print(a[j][i]);
                }
            }
            out.println();
        }



    }
}
