package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

public class AddingReversedNumbers {
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        StringBuilder a=new StringBuilder(String.valueOf(in.nextInt()));
        StringBuilder b=new StringBuilder(String.valueOf(in.nextInt()));

        int ra=0,rb=0;
        a=a.reverse();
        b=b.reverse();;

        int t=0;
        for (int i = a.length()-1; i>=0 ; i--)
        {   t=a.length()-1-i;
            ra+=Math.pow(10,t)*Character.getNumericValue(a.charAt(i));
        }
        for (int i = b.length()-1; i>=0 ; i--)
        {   t=b.length()-1-i;
            rb+=Math.pow(10,t)*Character.getNumericValue(b.charAt(i));
        }

        int ans=ra+rb;
        StringBuilder c=new StringBuilder(String.valueOf(ans));
        c=c.reverse();

        ans=0;
        for (int i = c.length()-1; i>=0 ; i--)
        {   t=c.length()-1-i;
            ans+=Math.pow(10,t)*Character.getNumericValue(c.charAt(i));
        }
        out.println(ans);
    }
}
