class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(1e9);
        int l = 0;
        int r = nums.size()-1;
        if(nums[0]>=target)
        {
            return 0;
        }
        while(l<r)
        {
            int mid = (l+r)/2;
            if(nums[mid]<target and nums[mid+1]>=target)
            {
                return mid+1;
            }
            else if(nums[mid]<target)
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        return -1;
    }
};