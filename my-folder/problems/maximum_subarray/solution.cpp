class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans=INT_MIN; 
        vector<int> dp;
        dp.push_back(nums[0]);
        ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp.push_back(max(dp.back()+nums[i],nums[i]));
            ans = max(ans,dp.back());
        } 

        return ans;
    }
};