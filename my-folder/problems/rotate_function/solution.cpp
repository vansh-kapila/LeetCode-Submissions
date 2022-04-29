class Solution
{
    public:
        int maxRotateFunction(vector<int> &nums)
        {
            int ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                ans = ans + nums[i] *i;
            }
            int ret = ans;
            int sum = 0;
            sum = accumulate(nums.begin(), nums.end(), sum);
            for (int j = nums.size() - 1; j >= 1; j--)
            {
                ans = ans - (nums.size()) *nums[j] + sum;
                ret = max(ret, ans);
            }
            return ret;
        }
};