class Solution
{
    public:
        bool allvis(vector<vector < int>> &vis, vector< vector< int>> &grid)
        {
            for (int i = 0; i < vis.size(); i++)
            {
                for (int j = 0; j < vis[i].size(); j++)
                {
                    if (grid[i][j] == 0 and vis[i][j] != 1)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }

    int solve(vector<vector < int>> &grid, int x, int y, int a, int b, vector< vector< int>> &vis)
    {
        if (x == a and y == b and allvis(vis, grid))
        {
            return 1;
        }
        else if (x == a and y == b)
        {
            return 0;
        }
        if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] == -1 or vis[x][y] >= 1)
        {
            return 0;
        }
        vis[x][y]++;
        int ans = solve(grid, x + 1, y, a, b, vis) + solve(grid, x, y + 1, a, b, vis) + solve(grid, x - 1, y, a, b, vis) + solve(grid, x, y - 1, a, b, vis);
        vis[x][y]--;
        return ans;
    }
    int uniquePathsIII(vector<vector < int>> &grid)
    {
        int sourcex, sourcey, destx, desty;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    sourcex = i;
                    sourcey = j;
                    break;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    destx = i;
                    desty = j;
                    break;
                }
            }
        }
        vector<vector < int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
        return solve(grid, sourcex, sourcey, destx, desty, vis);
    }
};