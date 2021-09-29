class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        else{
         int ans[n];
         ans[0] = nums[0];
         ans[1] = max(nums[1],nums[0]); 
         for(int i = 2;i<n;i++)
         {
             ans[i]=max(nums[i]+ans[i-2],ans[i-1]);
         }
        
        return ans[n-1];}
    }
};