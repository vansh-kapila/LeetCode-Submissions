class Solution {
public:
    int solve(vector<vector<int>> &grid,int x1,int y1,int x2,int y2,vector<vector<vector<int>>> &dp)
    {
        if(x1<0 or y1<0 or x2<0 or y2<0 or x1>=grid.size() or y1>=grid[0].size() or x2>=grid.size() or y2>=grid[0].size())
        {
            return 0;
        }
        if(dp[x1][y1][y2]!=-1)
        {
            return dp[x1][y1][y2];
        }
        int x = grid[x1][y1];
        grid[x1][y1] = 0;
        int y = grid[x2][y2];
        grid[x2][y2] = 0;
        int ans = x+y+max({solve(grid,x1+1,y1-1,x2+1,y2-1,dp),solve(grid,x1+1,y1+1,x2+1,y2-1,dp),solve(grid,x1+1,y1,x2+1,y2-1,dp),solve(grid,x1+1,y1-1,x2+1,y2,dp),solve(grid,x1+1,y1+1,x2+1,y2,dp),solve(grid,x1+1,y1,x2+1,y2,dp),solve(grid,x1+1,y1-1,x2+1,y2+1,dp),solve(grid,x1+1,y1,x2+1,y2+1,dp),solve(grid,x1+1,y1+1,x2+1,y2+1,dp)});
        grid[x1][y1] = x;
        if(x1!=x2 or y1!=y2)
        {
            grid[x2][y2] = y;
        }
        return dp[x1][y1][y2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int x1 = 0,y1 = 0;
        int x2 = 0,y2 = grid[0].size()-1;
        vector<vector<vector<int>>> dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(grid[0].size()+1,-1)));
        return solve(grid,x1,y1,x2,y2,dp);
    }
};