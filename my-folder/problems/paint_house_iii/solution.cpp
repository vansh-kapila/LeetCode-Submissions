class Solution
{
    public:
        int solve(vector<int> &houses, vector<vector< int >> &cost, int m, int n, int target, int last, vector< vector< vector< int>>> &dp)
        {
            if(target<0)
            {
                return 1e9;
            }
            if (m == 0 and target != 0)
            {
                return 1e9;
            }
            if (m == 0 and target == 0)
            {
                return 0;
            }
            if (dp[m - 1][target][last+1] != -1)
            {
                return dp[m - 1][target][last+1];
            }
            int ans = 1e9;
            for (int i = 1; i <= n; i++)
            {
                if (houses[m - 1] != 0)
                {
                    ans = min(solve(houses, cost, m - 1, n, target - (houses[m - 1] != last), houses[m - 1], dp), ans);
                }
                else
                {
                    ans = min(cost[m - 1][i - 1] + solve(houses, cost, m - 1, n, target - (i != last), i, dp), ans);
                }
            }
            return dp[m - 1][target][last+1] = ans;
        }
    int minCost(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target)
    {
        vector<vector<vector< int>>> dp(m + 1, vector<vector< int>> (target + 1, vector<int> (n + 2, -1)));
        int ans = solve(houses, cost, m, n, target, -1, dp);
        if (ans >= 1e9)
        {
            return -1;
        }
        return ans;
    }
};