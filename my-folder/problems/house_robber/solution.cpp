class Solution {
public:
    int solve(vector<int> &nums,int n,bool last_taken,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n-1][last_taken]!=-1)
        {
            return dp[n-1][last_taken];
        }
        int inc = 0;
        int exc = 0;
        if(!last_taken)
        {
            inc = nums[n-1]+solve(nums,n-1,1,dp);
        }
        exc = solve(nums,n-1,0,dp);
        return dp[n-1][last_taken]=max(inc,exc);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1);
        for(int i=0;i<nums.size()+1;i++)
        {
            dp[i].push_back(-1);
            dp[i].push_back(-1);
        }
        return solve(nums,nums.size(),0,dp);
    }
};