class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            if(nums.size()==1)
            {
                return nums[0];
            }
            if(nums[0]!=nums[1])
            {
                return nums[0];
            }
            if(nums[nums.size()-1]!=nums[nums.size()-2])
            {
                return nums[nums.size()-1];
            }
            int l = 1;
            int r = nums.size() / 2;

            while (l < r)
            {
                int mid = (l + r) / 2;
                if (nums[2 *mid - 1] != nums[2 *mid] and(2 *mid + 1 == nums.size() or nums[2 *mid] != nums[2 *mid + 1]))
                {
                    return nums[2*mid];
                }
                else if (nums[2 *mid] == nums[2 *mid + 1])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            return -1;
        }
};