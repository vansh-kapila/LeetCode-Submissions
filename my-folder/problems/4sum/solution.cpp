class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            set<vector < int>> s;
            map < long long, int> ind;
            long long n = nums.size();
            set<int> c;
            for (int i = 0; i < n; i++)
            {
                ind[nums[i]] = i + 1;
                c.insert(nums[i]);
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {    
                        long long y = (long long)(target) - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
                        if (y >= INT_MIN and c.find(y) != c.end() and ind[target - nums[i] - nums[j] - nums[k]] - 1 > k)
                        {
                            vector<int> v = { nums[i],
                                nums[j],
                                nums[k],
                                nums[ind[target - nums[i] - nums[j] - nums[k]] - 1]
                            };
                            sort(v.begin(), v.end());
                            s.insert(v);
                        }
                    }
                }
            }
            vector<vector < int>> ans;
            for (auto i: s)
            {
                ans.push_back(i);
            }
            return ans;
        }
};