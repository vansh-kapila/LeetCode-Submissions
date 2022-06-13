class Solution {
public:
    int numsum=0;
    bool solve(vector<int> &nums,int sum,int i,vector<int> &dp)
    {   
        if(sum==numsum/2 and i>=0)
        {
            return 1;
        }
        if(i==0)
        {
            return 0;
        }
        if(dp[sum]!=-1)
        {
            return dp[sum];
        }
        return dp[sum]=(int)solve(nums,sum-nums[i-1],i-1,dp)|solve(nums,sum,i-1,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(sum%2)
        {
            return 0;
        }
        numsum = sum;
        vector<int> dp(sum+1,-1);
        return solve(nums,sum,nums.size(),dp);
    }
};