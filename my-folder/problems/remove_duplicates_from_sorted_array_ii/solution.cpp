class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j = 0;
        if(nums.size()<=2)
        {
            return nums.size();
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i<2 || nums[i]>nums[j-2])
            {
                nums[j++]=nums[i];
            }
        }
        
        return j;
    }
};