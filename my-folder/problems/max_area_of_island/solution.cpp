class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        map<pair<int,int> ,int> mp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(mp[{i,j}])
                {
                    continue;
                }
                queue<pair<int,int>> q;
                if(grid[i][j]==1 and !mp[{i,j}])
                {
                    q.push({i,j});
                }
                int count = 0;
                while(!q.empty())
                {
                    pair<int,int> p = q.front();
                    q.pop();
                    i = p.first;
                    j = p.second;
                    if(mp[{i,j}])
                    {
                        continue;
                    }
                    mp[{i,j}]=1;
                    count++;
                    if(i+1<grid.size() and grid[i+1][j]==1 and !mp[{i+1,j}])
                    {
                        q.push({i+1,j});
                    }
                    if(j+1<grid[0].size() and grid[i][j+1]==1 and !mp[{i,j+1}])
                    {
                        q.push({i,j+1}); 
                    }
                    if(i-1>=0 and grid[i-1][j]==1 and !mp[{i-1,j}])
                    {
                        q.push({i-1,j}); 
                    }
                    if(j-1>=0 and grid[i][j-1]==1 and !mp[{i,j-1}])
                    {
                        q.push({i,j-1}); 
                    }
                } 
                ans = max(ans,count);
            }
        }
        return ans;
    }
};