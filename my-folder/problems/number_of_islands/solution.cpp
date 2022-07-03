class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        auto it = q.front();
                        q.pop();
                        if(it.first+1<grid.size() and grid[it.first+1][it.second]=='1')
                        {
                            q.push({it.first+1,it.second});
                            grid[it.first+1][it.second]='2';
                        }
                        if(it.first-1>=0 and grid[it.first-1][it.second]=='1')
                        {
                            q.push({it.first-1,it.second});
                            grid[it.first-1][it.second]='2';
                        }
                        if(it.second+1<grid[0].size() and grid[it.first][it.second+1]=='1')
                        {
                            q.push({it.first,it.second+1});
                            grid[it.first][it.second+1]='2';
                        }
                        if(it.second-1>=0 and grid[it.first][it.second-1]=='1')
                        {
                            q.push({it.first,it.second-1});
                            grid[it.first][it.second-1]='2';
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};