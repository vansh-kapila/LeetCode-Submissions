class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ts;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int l = i+1;
            int r = n-1;
            vector<int> v;
            while(l<r)
            {
                if(nums[l]+nums[r]+nums[i]==0)
                {
                     
                        v.push_back(nums[i]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        l++;
                        ts.push_back(v);
                        v.clear();
                        while(l<i and nums[l]==nums[l+1])
                        {
                            l++;
                        }
                    
                        while(r>i and nums[r]==nums[r-1])
                        {
                            r--;
                        }
                }
                else if(nums[l]+nums[r]+nums[i]>0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        sort(ts.begin(),ts.end());
        ts.erase( unique( ts.begin(), ts.end() ), ts.end() );
        return ts;
    }
};