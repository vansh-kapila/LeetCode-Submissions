class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        if(r==1)
        {
            return 0;
        }
        if(r==2)
        {
            if(nums[0]>nums[1])
            {
                return 0;
            }
            return 1;
        }
        while(l<r)
        {
            int mid = (l+r)/2;
            if(mid>0 and mid<nums.size()-1 and nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if(mid==0 or nums[mid]>nums[mid-1])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        if(nums[nums.size()-1]>nums[0])
        {
          return nums.size()-1;   
        }
        return 0;
    }
};