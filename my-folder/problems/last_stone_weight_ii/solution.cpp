class Solution {
public:
    int sum = 0;
    int solve(vector<int> &stones,int n,int subsetsum,vector<int> &dp)
    {
        if(n==0)
        {
            return abs(sum-2*subsetsum);
        }
        if(dp[subsetsum]!=-1)
        {
            return dp[subsetsum];
        }
        int inc = solve(stones,n-1,subsetsum+stones[n-1],dp);
        int exc = solve(stones,n-1,subsetsum,dp);
        return dp[subsetsum]=min(inc,exc);
    }
    int lastStoneWeightII(vector<int>& stones) {
        sum = accumulate(stones.begin(),stones.end(),sum);
        vector<int> dp(sum,-1);
        return solve(stones,stones.size(),0,dp);
    }
};