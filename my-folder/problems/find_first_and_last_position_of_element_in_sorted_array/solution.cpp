class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int ans1=-1;int ans2=-1;
        while(l<=r)
        {   int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                ans1 = mid;
                r = mid-1;
            }
         
         else if(nums[mid]<target)
         {
             l = mid+1;
         }
         else
         {
             r=mid-1;
         }
            
        }
        l = 0;
        r = nums.size()-1;
        while(l<=r)
        {   int mid = (l+r)/2;
            if(nums[mid]==target)
            {
                ans2 = mid;
                l = mid+1;
            }
         
         else if(nums[mid]<target)
         {
             l = mid+1;
         }
         else
         {
             r=mid-1;
         }
            
        }
        
        vector<int> v;
        v.push_back(ans1);
        v.push_back(ans2);
        
        return v;
    }
};