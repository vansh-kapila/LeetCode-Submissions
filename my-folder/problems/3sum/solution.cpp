class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        set<vector<int>> ans;
        vector<vector<int>> ans2;
        if(nums.size()<=2)
        {
            return ans2;
        }
        for(int i=2;i<nums.size();i++)
        {
            int x = nums[i];
            int l = 0;
            int r = i-1;
            if(x+nums[l]+nums[l+1]>0)
            {
                continue;
            }
            if(x+nums[r]+nums[r-1]<0)
            {
                continue;
            }
            while(l<r)
            {
                if(l<i and r<i and nums[l]+nums[r]+nums[i]==0)
                {
                    ans.insert({nums[l],nums[i],nums[r]});
                    l++;
                    r--;
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
        for(auto i:ans)
        {
            ans2.push_back(i);
        }
        return ans2;
    }
};