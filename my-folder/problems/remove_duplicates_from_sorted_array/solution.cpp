class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[count++]=nums[i];
            }
        }
        nums[count++]=nums.back();
        return count;
    }
};