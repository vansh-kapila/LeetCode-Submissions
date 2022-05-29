class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int buy = INT_MAX;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            buy = min(buy,nums[i]);
            ans = max(ans,nums[i]-buy);
        }
        return ans;
    }
};