class Solution {
public:
    int helper(vector<vector<int>> &grid,int m,int n,vector<vector<int>> &dp)
    {
        if(m==0 and n==0)
        {
            return grid[0][0];
        }
        if(m<0 or n<0)
        {
            return 100000007;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int right = grid[m][n]+helper(grid,m-1,n,dp);
        int down = grid[m][n]+helper(grid,m,n-1,dp);
        
        return dp[m][n]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i].push_back(-1);
            }
        }
        return helper(grid,m-1,n-1,dp);
    }
};