class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {   
            map<int,int> m;
            for(auto i:nums)
            {
                m[i]++;
            }
            nums.clear();
            for(auto i:m)
            {   
                for(int j=0;j<min(i.second,3);j++)
                {
                    nums.push_back(i.first);
                }
            }
            set<vector < int>> s;
            sort(nums.begin(), nums.end());
            if (nums.size() == 1 or nums.size() == 0)
            {
                vector<vector < int>> v;
                return v;
            }
            for (int i = 0; i < nums.size() - 2; i++)
            {
                int l = i + 1;
                int r = nums.size() - 1;
                if(nums[r-1]+nums[r]+nums[i]<0)
                {
                    continue;
                }
                if(nums[l]+nums[l+1]+nums[i]>0)
                {
                    break;
                }
                while (l < r)
                {
                    if (nums[l] + nums[r] + nums[i] == 0)
                    {
                        s.insert({ nums[i],
                            nums[l],
                            nums[r] });
                        l++;
                        r--;
                    }
                    else if (nums[l] + nums[r] + nums[i] > 0)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
            vector<vector < int>> ans;
            for (auto &i: s)
            {
                ans.push_back(i);
            }

            return ans;
        }
};