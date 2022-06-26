class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0 and (i==j or i==grid.size()-1-j))
                {
                    return 0;
                }
                if(grid[i][j]!=0 and (i!=j and i!=grid.size()-1-j))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};