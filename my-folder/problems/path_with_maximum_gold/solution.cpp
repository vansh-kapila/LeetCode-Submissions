class Solution {
public:
    int solve(vector<vector<int>> &grid,int i,int j)
    {
        if(i<0 or i>grid.size()-1 or j<0 or j>grid[0].size()-1 or grid[i][j]==0)
        {
            return 0;
        }
        int y = grid[i][j];
        grid[i][j]=0;
        int a = solve(grid,i+1,j);
        int b = solve(grid,i,j+1);
        int c = solve(grid,i,j-1);
        int d = solve(grid,i-1,j);
        grid[i][j] = y;
        return y+max({a,b,c,d});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {   
                vector<vector<int>> grid2 = grid;
                ans = max(solve(grid2,i,j),ans);
            }
        }
        return ans;
    }
};