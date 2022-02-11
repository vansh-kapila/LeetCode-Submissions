class Solution {
public:
    int dp[22][2000];
    int solve(vector<int> &nums,int i,int target,int sum)
    {  
        if(i==nums.size() and target==sum)
        {
            return 1;
        }
        else if(i==nums.size())
        {
            return 0;
        }
        if(dp[i][sum+1000]!=-1)
        {
            return dp[i][sum+1000];
        }
        int exc = solve(nums,i+1,target,sum-nums[i]);
        int inc = solve(nums,i+1,target,sum+nums[i]);
        return dp[i][sum+1000]=inc+exc;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        for(int i=0;i<nums.size()+1;i++)
        {
            for(int j=0;j<2000;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(nums,0,target,0);
    }
};