class Solution
{
    public:
        int maxOperations(vector<int> &nums, int k)
        {
            unordered_multiset<int> ms;
            for (auto i: nums)
            {
                ms.insert(i);
            }
            sort(nums.begin(),nums.end());
            int ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (ms.find(k - nums[i]) != ms.end())
                {
                    ms.erase(ms.find(k - nums[i]));
                    if (ms.find(nums[i]) != ms.end())
                    {
                        ms.erase(ms.find(nums[i]));
                        ans++;
                    }
                }  
                if(ms.empty())
                {
                    break;
                }
            }
            return ans;
        }
};