class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            unordered_map<int, int> m;
            for (int i = 0; i < nums.size(); i++)
            {
                m[nums[i]] = i;
            }
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++)
            {
                if (m.find(target - nums[i]) != m.end())
                {
                    auto it = m.find(target - nums[i]);
                    if (it->second != i)
                    {
                        ans.push_back(i);
                        ans.push_back(it->second);
                        break;
                    }
                }
            }
            return ans;
        }
};