class Solution
{
    public:
        int solve(int amount, vector<int> &coins, int i,vector<vector<int>> &dp)
        {
            if (amount == 0)
            {
                return 1;
            }
            if(dp[amount][i]!=-1)
            {
                return dp[amount][i];
            }
            int ans = 0;
            for (int j = i; j < coins.size(); j++)
            {
                if (amount >= coins[j])
                {
                    ans = ans + solve(amount - coins[j], coins, j,dp);
                } 
                else
                {
                    break;
                }
            }
            return dp[amount][i]=ans;
        }
    int change(int amount, vector<int> &coins)
    {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
        return solve(amount, coins, 0,dp);
    }
};