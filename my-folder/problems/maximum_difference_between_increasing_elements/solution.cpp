class Solution {
public:
    int maximumDifference(vector<int>& nums) { 
        
        int piv = nums[0];
        int ans = -1;
        int k = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<piv)
            {
                piv = nums[i];
            }
            if(nums[i]-piv>max(ans,k))
            {
                ans = nums[i]-piv;
            }
        }
        
        return ans;
    }
};