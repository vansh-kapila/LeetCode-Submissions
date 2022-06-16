class Solution
{
    public:
        int orangesRotting(vector<vector < int>> &grid)
        {
            queue<pair<pair<int, int>,int>> q;
            int count = 0;
            map<pair<int,int>,bool> vis;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 2)
                    {
                        q.push({{ i,j },0});
                        vis[{i,j}]=1;
                        count++;
                    }
                    else if (grid[i][j] == 1)
                    {
                        count++;
                    }
                }
            } 
            if(count==0)
            {
                return 0;
            }
            int ans = 0;
            while (!q.empty())
            {
                pair<pair<int, int>,int> p = q.front();
                q.pop();
                count--;
                vis[{p.first.first,p.first.second}]=1;
                if (!vis[{p.first.first-1,p.first.second}] and p.first.first>0 and grid[p.first.first - 1][p.first.second] == 1) 
                { 
                    q.push({{p.first.first-1,p.first.second},p.second+1});
                    vis[{p.first.first-1,p.first.second}]=1; 
                }
                if (!vis[{p.first.first,p.first.second-1}] and p.first.second>0 and grid[p.first.first][p.first.second-1] == 1) 
                { 
                    q.push({{p.first.first,p.first.second-1},p.second+1});
                    vis[{p.first.first,p.first.second-1}]=1; 
                }
                if (!vis[{p.first.first+1,p.first.second}] and p.first.first<grid.size()-1 and grid[p.first.first + 1][p.first.second] == 1) 
                { 
                    q.push({{p.first.first+1,p.first.second},p.second+1});
                    vis[{p.first.first+1,p.first.second}]=1; 
                }
                if (!vis[{p.first.first,p.first.second+1}] and p.first.second+1<grid[0].size() and grid[p.first.first][p.first.second+1] == 1) 
                { 
                    q.push({{p.first.first,p.first.second+1},p.second+1});
                    vis[{p.first.first,p.first.second+1}]=1; 
                }
                if(count==0)
                {
                    return p.second;
                }
            } 
            return -1;
        }
};