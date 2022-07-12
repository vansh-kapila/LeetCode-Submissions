class Solution {
public:
    int solve(vector<int> &cost,int n,vector<int> &dp)
    {
        if(n<0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=min(cost[n]+solve(cost,n-1,dp),cost[n]+solve(cost,n-2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        vector<int> dp2(cost.size(),-1);
        return min(solve(cost,cost.size()-1,dp),solve(cost,cost.size()-2,dp2));
    }
};