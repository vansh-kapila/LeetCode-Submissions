class Solution {
public:
    int solve(vector<int> &nums,int i,int j,vector<int> &dp)
    {
        if(i==nums.size())
        {
            return 0;
        }
        if(dp[j+1]!=-1)
        {
            return dp[i];
        }
        int inc = -1;
        if(j==-1 or nums[i]>nums[j])
        {
           inc = 1+solve(nums,i+1,i,dp);
        }
        int exc = solve(nums,i+1,j,dp);
        
        return dp[j+1]=max(inc,exc);
    }
    int lengthOfLIS(vector<int>& nums) 
    {   
        vector<int> dp(nums.size()+2);
        for(int i=0;i<nums.size()+2;i++)
        { 
           dp[i] = (-1); 
        }
        return solve(nums,0,-1,dp);
    }
};