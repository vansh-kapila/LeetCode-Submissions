class Solution
{
    public:
        vector<int> sortArrayByParity(vector<int> &nums)
        {
            int l = 0, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[l] % 2 == 1 and nums[r] % 2 == 0)
                {
                    swap(nums[l], nums[r]);
                    l++;
                    r--;
                }
                else if (nums[r] % 2 == 1)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
            return nums;
        }
};