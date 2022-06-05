class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int count = 1;
        int minn = nums[0];
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-minn>k)
            {
                count++;
                minn = nums[i+1];
            }
        }
        return count;
    }
};