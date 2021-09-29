class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int ans[n];
        ans[0]=nums[0];
        int c = nums[0];
        for(int i=1;i<n;i++)
        {
            ans[i]=max(nums[i],ans[i-1]+nums[i]);
            c = max(ans[i],c);
        }
        
        return c;
    }
};