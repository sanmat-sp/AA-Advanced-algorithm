#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std

int LCS(string X, string Y)
{
        int m = strlen(X);
        int n = strlen(Y);
        int dp[m+1][n+1];
        int i,j;
        
        for(i=0;i<=m;i++)
        {
                dp[i][0]=0;
        }
        for(j=0;j<=n;j++)
        {
                dp[0][j]=0;
        }

        for(i=0;i<=m;i++)
        {
                for(j=0;j<=n;j++)
                {
                        if(i==0 || j==0)
                        {
                                dp[i][j]=0;
                        }
                        else if(X[i-1]==y[j-1])
                        {
                                dp[i][j] = dp[i-1][j-1]+1;
                        }
                        else if(dp[i-1][j]>dp[i][j-1])
                        {
                                dp[i][j]=dp[i-1][j];
                        }
                        else
                        {
                                dp[i][j]=dp[i][j-1];
                        }
                }
        }
        cout<<dp[m][n]<<endl;

        string LCS_seq;
        i=m;
        j=n;
        while(i>0 && j>0)
        {
                if(X[i-1]==Y[j-1])
                {
                        LCS_seq.push_back(X[i-1]);
                        i--;
                        j--;
                }
                else if(dp[i][j-1] > dp[i-1][j])
                {
                        j--;
                }
                else
                {
                        i--;
                }
        }
        reverse(LCS_seq.begin(), LCS_seq.end());
        cout<<LCS_seq<<endl;
        return 0;
}

int main()
{
        string A, B;
        cin>>A>>B;
        int a=LCS(A, B);
        return 0;
}
