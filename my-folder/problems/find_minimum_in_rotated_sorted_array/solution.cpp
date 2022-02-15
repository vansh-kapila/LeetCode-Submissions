class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size();
        while(l<r)
        {
            int mid = (l+r)/2;
            if(mid>0 and nums[mid]<nums[mid-1])
            {
                return nums[mid];
            }
            else if(nums[mid]<nums[0])
            {
                r = mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return nums[0];
    }
};