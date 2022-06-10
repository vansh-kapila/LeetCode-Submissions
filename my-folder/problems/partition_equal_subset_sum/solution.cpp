class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numsum = 0;
        numsum = accumulate(nums.begin(),nums.end(),numsum);
        if(numsum%2)
        {
            return 0;
        }
        vector<int> dp(numsum/2+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=numsum/2;j>=0;j--)
            {
                if(nums[i]<=j)
                {
                    dp[j]=dp[j]|dp[j-nums[i]];
                }
            }
        }
        return dp[numsum/2];
    }
};