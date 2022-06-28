class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<nums.size()-1;i++)
        { 
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            bool smol = 0,great = 0;
            for(int j=i;j>=0;j--)
            {
                if(nums[j]!=nums[i] and nums[j]>nums[i])
                {
                    great = 1;
                    break;
                }
                if(nums[j]!=nums[i] and nums[j]<nums[i])
                {
                    smol = 1;
                    break;
                }
            }
            bool smol2 = 0,great2 = 0;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]!=nums[i] and nums[j]>nums[i])
                {
                    great2 = 1;
                    break;
                }
                if(nums[j]!=nums[i] and nums[j]<nums[i])
                {
                    smol2 = 1;
                    break;
                }
            }
            count+=(smol&smol2)+(great&great2);
        } 
        return count;
    }
};