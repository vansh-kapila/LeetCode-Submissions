class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums2 = nums;
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.size()-1;
        while(l<nums.size())
        {
            if(nums[l]==nums2[l])
            {
                l++;
            }
            else
            {
                break;
            }
        }
        while(r>l)
        {
            if(nums[r]==nums2[r])
            {
                r--;
            }
            else
            {
                break;
            }
        }
        
        if(r<l)
        {
            return 0;
        }
        return r-l+1;
    }
};