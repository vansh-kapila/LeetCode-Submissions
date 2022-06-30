class Solution {
public:
    int solve(vector<vector<int>> &matrix,int n,int m,vector<vector<int>> &dp)
    { 
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        int ans = 0;
        if(n>=1 and matrix[n-1][m]>matrix[n][m])
        {
            ans = max(ans,1+solve(matrix,n-1,m,dp));
        }
        if(m>=1 and matrix[n][m-1]>matrix[n][m])
        {
            ans = max(ans,1+solve(matrix,n,m-1,dp));
        }
        if(n+1<matrix.size() and matrix[n+1][m]>matrix[n][m])
        {
            ans = max(ans,1+solve(matrix,n+1,m,dp));
        }
        if(m+1<matrix[0].size() and matrix[n][m+1]>matrix[n][m])
        {
            ans = max(ans,1+solve(matrix,n,m+1,dp));
        }
        return dp[n][m]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                ans = max(ans,solve(matrix,i,j,dp));
            }
        }
        return ans+1;
    }
};