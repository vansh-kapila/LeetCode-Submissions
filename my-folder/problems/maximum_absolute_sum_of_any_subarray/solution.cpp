class Solution {
public:
    int maxsum(vector<int> &nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=(nums[i])*(-1);
        }
        int ans = nums[0];
        int sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum = max(nums[i],sum+nums[i]);
            ans = max(ans,sum); 
        }
        return ans;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        
        return max(maxsum(nums),maxsum(nums));
    }
};