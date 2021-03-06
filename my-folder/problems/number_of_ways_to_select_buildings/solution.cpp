class Solution {
public:
long long count(string &a, string &b)
{
    long long m = a.length();
    long long n = b.length();
  
    long long dp[m + 1][n + 1];
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            dp[i][j]=0;
        }
    }
    for (int i = 0; i <= n; ++i)
        dp[0][i] = 0;
  
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 1;
  
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        { 
            if (a[i - 1] == b[j - 1])
            {dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];}
                 
            else 
            {dp[i][j] = dp[i - 1][j];}
        }
    }
 
    return dp[m][n];
}

    long long numberOfWays(string s) {
        long long ans = 0; 
        int counto = 0;
        int countz = 0;
        string x = "101";
        string y = "010";
        int dp[s.length()+1];
        return count(s,x)+count(s,y);
    }
};