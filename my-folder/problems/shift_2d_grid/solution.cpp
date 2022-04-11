class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size())); 
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {  
                ans[(i+(j+k)/grid[0].size())%grid.size()][(j+k)%grid[0].size()]=grid[i][j];
            }
        }
        return ans;
    }
};