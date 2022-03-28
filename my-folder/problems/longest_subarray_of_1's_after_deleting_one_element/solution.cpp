class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lasto = 0;
        int curr = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                curr++;
            }
            else if(nums[i]==0)
            {
               ans = max(ans,curr+lasto);
               lasto = curr;
               curr = 0;
            }
        }
        ans = max(ans,curr+lasto);
        if(ans==nums.size())
        {
            return ans-1;
        }
        return ans;
    }
};