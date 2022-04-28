class Solution
{
    public:
        bool solve(vector<vector < int>> &heights, int x, int y, int mid, vector< vector< int>> &vis)
        {
            if (x == heights.size() - 1 and y == heights[0].size() - 1)
            {
                return 1;
            } 
            vis[x][y] = 1;
            bool ans = 0;
            if (x + 1 < heights.size() and vis[x + 1][y] == 0 and abs(heights[x + 1][y] - heights[x][y]) <= mid)
            {
                ans = (ans|(solve(heights, x + 1, y, mid, vis)));
            }
            if (y + 1 < heights[0].size() and vis[x][y + 1] == 0 and abs(heights[x][y + 1] - heights[x][y]) <= mid)
            {
                ans = (ans|(solve(heights, x, y + 1, mid, vis)));
            }
            if (x - 1 >= 0 and vis[x - 1][y] == 0 and abs(heights[x][y] - heights[x - 1][y]) <= mid)
            {
                ans = (ans|(solve(heights, x - 1, y, mid, vis)));
            }
            if (y - 1 >= 0 and vis[x][y - 1] == 0 and abs(heights[x][y - 1] - heights[x][y]) <= mid)
            {
                ans = (ans|(solve(heights, x, y - 1, mid, vis)));
            }
            return ans;
        }
    int minimumEffortPath(vector<vector < int>> &heights)
    {

        int l = 0;
        int r = 1e6;
        vector<vector < int>> vis;
        vis.resize(heights.size() + 1);
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = 0; j < heights[i].size(); j++)
            {
                vis[i].push_back(0);
            }
        }

        while (l < r)
        {
            int mid = (l+r)/ 2;
            if (solve(heights, 0, 0, mid, vis))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
            for (int i = 0; i < heights.size(); i++)
            {
                for (int j = 0; j < heights[i].size(); j++)
                {
                    vis[i][j] = 0;
                }
            }
        }
        return r;
    }
};