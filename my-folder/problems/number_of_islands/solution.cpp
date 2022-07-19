class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1' and !vis[i][j])
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        auto it = q.front();
                        q.pop();
                        if(it.first>=1 and !vis[it.first-1][it.second] and grid[it.first-1][it.second]=='1')
                        {
                            vis[it.first-1][it.second]=1;
                            q.push({it.first-1,it.second});
                        }
                        if(it.second>=1 and !vis[it.first][it.second-1] and grid[it.first][it.second-1]=='1')
                        {
                            vis[it.first][it.second-1]=1;
                            q.push({it.first,it.second-1});
                        }
                        if(it.first+1<grid.size() and !vis[it.first+1][it.second] and grid[it.first+1][it.second]=='1')
                        {
                            vis[it.first+1][it.second]=1;
                            q.push({it.first+1,it.second});
                        }
                        if(it.second+1<grid[0].size() and !vis[it.first][it.second+1] and grid[it.first][it.second+1]=='1')
                        {
                            vis[it.first][it.second+1]=1;
                            q.push({it.first,it.second+1});
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};