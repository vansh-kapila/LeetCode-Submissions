class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        { 
            int ind = -1;
            for (int i = nums.size() - 2; i >= 0; i--)
            {
                if (nums[i] < nums[i + 1])
                {
                    ind = i;
                    break;
                }
            }

            if (ind == -1)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
            int k = -1;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] > nums[ind])
                {
                    k = i;
                    break;
                }
            }
            swap(nums[ind], nums[k]);
            reverse(nums.begin() + ind + 1, nums.end());
        }
};