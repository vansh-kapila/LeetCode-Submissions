class Solution {
public:
    int solve(vector<int> &coins,int amount,vector<int> &dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(dp[amount]!=-1)
        {
            return dp[amount];
        }
        int ans = INT_MAX;
        for(auto i:coins)
        {
            if(amount-i>=0 and solve(coins,amount-i,dp)!=INT_MAX)
            {
                ans = min(ans, 1 + solve(coins,amount-i,dp));
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = solve(coins,amount,dp);
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};