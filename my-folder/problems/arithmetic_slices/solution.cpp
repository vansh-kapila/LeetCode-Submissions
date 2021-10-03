class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2)
        {
            return 0;
        }
        int n = nums.size();
        int k = 0;
        int ans = 0;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i+2]-nums[i+1]==nums[i+1]-nums[i])
            {
                k++;
                ans+=k;
            }
            else
            {
                k=0;
            }
        }
        return ans;
    }
};