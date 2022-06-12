class Solution
{
    public:

        int minPathCost(vector<vector < int>> &grid, vector< vector< int>> &moveCost)
        {

            vector<vector < int>> dp(grid.size() + 1);
            for (int i = 0; i <= grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    if (i == 0)
                    {
                        dp[i].push_back(grid[i][j]);
                    }
                    else
                    {
                        dp[i].push_back(1e9);
                    }
                }
            }

            for (int i = 1; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[0].size(); j++)
                {
                    for (int m = 0; m < grid[0].size(); m++)
                    {
                        dp[i][m] = min(dp[i][m], dp[i - 1][j] + grid[i][m] + moveCost[grid[i - 1][j]][m]);
                    }
                }
            }
            return* min_element(dp[grid.size() - 1].begin(), dp[grid.size() - 1].end());
        }
};