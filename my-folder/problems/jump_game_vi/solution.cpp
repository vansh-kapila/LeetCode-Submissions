class Solution
{
    public:
        int maxResult(vector<int> &nums, int k)
        {
            vector<int> dp(nums.size(), INT_MIN);
            dp[0] = nums[0];
            multiset<int> ms;
            ms.insert(dp[0]);
            for (int i = 1; i < nums.size(); i++)
            {
                if (i >= k+1)
                {
                    ms.erase(ms.find(dp[i - k-1]));
                }
                dp[i] = max(dp[i], nums[i] + *ms.rbegin());
                ms.insert(dp[i]);
            }
            return dp.back();
        }
};