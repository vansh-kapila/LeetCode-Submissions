class Solution
{
    public:
        bool find132pattern(vector<int> &nums)
        {
            vector<int> v;
            v.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++)
            {
                v.push_back(min(nums[i], v.back()));
            }
            set<int> s;
            s.insert(nums[nums.size() - 1]);
            for (int i = nums.size() - 2; i >= 0; i--)
            {
                if (nums[i] > v[i])
                {
                    auto it = s.lower_bound(nums[i]);
                    it--;
                    s.insert(nums[i]);
                    if (*it < nums[i] and * it > v[i])
                    {
                        return 1;
                    }
                }
            }
            return 0;
        }
};