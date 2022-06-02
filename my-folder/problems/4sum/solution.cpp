class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            vector<vector < int>> ans;
            sort(nums.begin(), nums.end());
            if (nums.size() == 1 or nums.size()==2)
            {
                return ans;
            }
            for (int i = 0; i < nums.size() - 3; i++)
            {
                for (int j = i + 1; j < nums.size() - 2; j++)
                {  
                    if(nums[i]+nums[j]>target and target>=0)
                    {
                        break;
                    }
                    if((long long)nums[i]+(long long)nums[j]+(long long)nums[j+1]+(long long)nums[j+2]>target)
                    {
                        break;
                    }
                    int lo = j + 1;
                    int hi = nums.size() - 1;
                    while (lo < hi)
                    {
                        if ((long long) nums[i] + (long long) nums[j] + (long long) nums[lo] + (long long) nums[hi] == target)
                        {
                            ans.push_back({ nums[i],
                                nums[j],
                                nums[lo],
                                nums[hi] });
                            lo++;
                            hi--;
                        }
                        else if ((long long) nums[i] + (long long) nums[j] + (long long) nums[lo] + (long long) nums[hi] > target)
                        {
                            hi--;
                        }
                        else
                        {
                            lo++;
                        }
                    }
                }
            }

            set<vector < int>> s(ans.begin(), ans.end());
            ans.clear();
            for (auto &i: s)
            {
                ans.push_back(i);
            }
            return ans;
        }
};