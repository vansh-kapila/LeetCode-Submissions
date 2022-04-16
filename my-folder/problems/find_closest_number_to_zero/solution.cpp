class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = 0;
        int prev = 100000007;
        sort(nums.begin(),nums.end());
        for(auto i:nums)
        {
            if(abs(i)<=prev)
            {
                ans = i;
                prev = abs(i);
            }
        }
        return ans;
    }
};