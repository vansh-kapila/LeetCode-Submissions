class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int o  = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            o+=nums[i];
            ans = max(ans,o);
            if(nums[i]==0)
            {
                o=0;
            }
        }
        ans = max(ans,o);
        return ans;
    }
};