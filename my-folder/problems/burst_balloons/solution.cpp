class Solution
{
    public:
        int solve(vector<int> &nums, int left, int right,vector<vector<int>> &dp)
        {
            if(left>=right)
            {
                return 0;
            }
            if(dp[left][right]!=-1)
            {
                return dp[left][right];
            }
            int ans = 0; 
            for (int i = left+1; i < right; i++)
            {
                ans = max(ans, nums[i] *nums[left] *nums[right] + solve(nums, left, i,dp) + solve(nums, i, right,dp));
            }
            return dp[left][right]=ans;
        }
    int maxCoins(vector<int> nums)
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(nums, 0, nums.size()-1,dp);
    }
};