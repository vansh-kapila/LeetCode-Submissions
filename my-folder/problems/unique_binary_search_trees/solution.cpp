class Solution {
public:
    int solve(int l,int r,vector<vector<int>> &dp)
    {
        if(l>=r)
        {
            return 1;
        } 
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        int ans = 0;
        for(int i=l;i<=r;i++)
        {
            ans = ans + solve(l,i-1,dp)*solve(i+1,r,dp);
        } 
        return dp[l][r]=ans;
    }
    int numTrees(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);
    }
};