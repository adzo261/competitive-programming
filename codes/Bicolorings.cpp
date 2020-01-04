    #include <bits/stdc++.h>
    using namespace std;
    #define endl "\n"
    const long long M=998244353;
    int compute(int nmask,int omask)
    {
        /*
            This function computes the number of components possible while considering a new ith column over all
            combinations of old and new masks

            For eg;

                    (i-1)th column      ith column(new)
            row 0       1                   0
            row 1       1                   1

            In this example,number of component increased as 1's are connected and '0'is new component
            Similarly,we can compute for all other combinations of oldmask and new mask */

        if(nmask==omask || omask==1 && (nmask==3 || nmask==0) || omask==2 && (nmask==3 || nmask==0))
            return 0;
        else if(nmask==1 && omask==2 || nmask==2 && omask==1)
            return 2;
        else return 1;

    }
    int main() 
    {
        
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        

        int n,k;
        cin>>n>>k;

        int mask=4;
        /* mask has four values 0(00),1(01),2(10),3(11) which denote the two rows of ith column as
              

                            column i:
        mask            00      01      10      11
        row 0           0/B     0/B     1/W     1/W
        row 1           0/B     1/W     0/B     1/W
    

        state dp[i][j][mask] denotes that i columns have been considered and j components have been decided ,
        and the ith column has component arrangement as denoted by mask on its rows.



        */
        int dp[n+1][k+3][mask];


        fill(&dp[0][0][0],&dp[0][0][0]+(n+1)*(k+3)*(mask),0);


        dp[1][1][0]=1;
        dp[1][1][3]=1;
        dp[1][2][1]=1;
        dp[1][2][2]=1;

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {

                for(int omask=0;omask<mask;omask++)
                {
                    for(int nmask=0;nmask<mask;nmask++)
                    {
                        dp[i][j+compute(nmask,omask)][nmask]=(dp[i][j+compute(nmask,omask)][nmask]%M+dp[i-1][j][omask]%M)%M;
                    }
                }
            }
        }

        long long ans=0;

        for(int i=0;i<mask;i++)
        {
            ans=(ans%M + dp[n][k][i]%M)%M;
        }

        cout<<ans<<endl;





        
            
        return 0;
    }
    