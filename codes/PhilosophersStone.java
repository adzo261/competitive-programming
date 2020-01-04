package CP;

import FastIO.InputReader;
import FastIO.OutputWriter;

public class PhilosophersStone
{
    public void solve(int testNumber, InputReader in, OutputWriter out)
    {
        int m=in.nextInt();
        int n=in.nextInt();
        int a[][]=new int[m][n];
        int dp[][]=new int[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j]=in.nextInt();

            }
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i]=a[0][i];
        }
        for (int i =1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i-1>=0 && i-1<m && j-1>=0 && j-1<n)
                    dp[i][j]=Math.max(dp[i][j],dp[i-1][j-1]+a[i][j]);
                if(i-1>=0 && i-1<m)
                    dp[i][j]=Math.max(dp[i][j],dp[i-1][j]+a[i][j]);
                if(i-1>=0 && i-1<m && j+1>=0 && j+1<n)
                    dp[i][j]=Math.max(dp[i][j],dp[i-1][j+1]+a[i][j]);
            }
        }
        int max=Integer.MIN_VALUE;
        for (int i = 0; i < n; i++)
        {
            max=Math.max(max,dp[m-1][i]);
        }
        out.println(max);
    }
}
