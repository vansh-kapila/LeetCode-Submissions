class Solution {
public: 
    int solve(vector<vector<int>> &dp,int n,int m)
    {
        if(n==0 and m==0)
        {   
            return 1;
        }
        if(n<0 or m<0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        int ans = solve(dp,n-1,m)+solve(dp,n,m-1);
        return dp[n][m]=ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n);
        dp.resize(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i].push_back(-1);
            }
        }
        return solve(dp,n-1,m-1);
    }
};