class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size();
        if(nums[l]==target)
        {
            return l;
        }
        if(nums[r-1]==target)
        {
            return r-1;
        }
        while(l<r)
        {
            int mid = (l+r)/2;
            if(nums[mid]==target)
            {
               return mid;
            } 
            else if(nums[mid]>nums[0] and target<nums[0])
            {
                l=mid+1;
            }
            else if(nums[mid]>nums[0] and target>nums[0] and target>nums[mid])
            {
                l=mid+1;
            }
            else if(nums[mid]<nums[0] and target<nums[0] and target>nums[mid])
            {
                l=mid+1;
            }
            else
            {
                r = mid;
            }
        }
        return -1;
    }
};