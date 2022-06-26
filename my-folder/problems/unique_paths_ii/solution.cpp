class Solution {
public:
    int solve(vector<vector<int>> &obstacle,int i,int j,vector<vector<int>> &dp)
    {
        if(i==obstacle.size()-1 and j==obstacle[0].size()-1 and obstacle[i][j]!=1)
        {
            return 1;
        }
        if(i<0 or j<0 or i>=obstacle.size() or j>=obstacle[0].size() or obstacle[i][j]==1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=solve(obstacle,i+1,j,dp)+solve(obstacle,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int> (obstacleGrid[0].size(),-1));
        return solve(obstacleGrid,0,0,dp);
    }
};