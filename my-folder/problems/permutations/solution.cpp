class Solution
{
    public:
        void nextperm(vector<int> &nums)
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
                nums.clear();
                return;
            }
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] > nums[ind])
                {
                    swap(nums[ind], nums[i]);
                    reverse(nums.begin() + ind + 1, nums.end());
                    return;
                }
            }
        }
    vector<vector < int>> permute(vector<int> &nums)
    {
        vector<vector < int>> ans; 
        sort(nums.begin(),nums.end());
        while (!nums.empty())
        {
            ans.push_back(nums);
            nextperm(nums);
        }
        return ans;
    }
};