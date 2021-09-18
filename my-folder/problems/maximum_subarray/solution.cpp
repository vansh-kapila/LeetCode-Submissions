class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        int sum = nums[0];
        for(int i=1;i<n;i++)
        {
            x = max(x+nums[i],nums[i]);
            sum = max(x,sum);
        }
        return sum;
    }
};