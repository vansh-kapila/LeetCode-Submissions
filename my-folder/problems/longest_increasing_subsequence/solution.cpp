class Solution {
public:
    int solve(vector<int> &nums,int n,int last,vector<vector<int>> &dp)
    {
        if(n==nums.size())
        {
            return 0;
        } 
        if(dp[n][last+1]!=-1)
        {
            return dp[n][last+1];
        }
        int inc = -1,exc = -1;
        if(last==-1 or nums[n]>nums[last])
        {
            inc = 1+solve(nums,n+1,n,dp);
        }
        exc = solve(nums,n+1,last,dp);
        
        return dp[n][last+1]=max(inc,exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,dp);
    }
};