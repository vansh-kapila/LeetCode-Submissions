class Solution {
public:
    int numSquares(int n) {
        
        int dp[n+1];
        for(int i=0;i<n+1;i++)dp[i]=100000007;
        dp[0]=0; 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=min(dp[i-j*j]+1,dp[i]);
            }
        }
        
        return dp[n];
    }
};