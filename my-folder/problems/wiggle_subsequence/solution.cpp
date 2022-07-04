class Solution {
public: 
    int solve(vector<int> &nums,int n,int lasttaken,bool greater,vector<vector<vector<int>>>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        int ans = 0; 
        if(lasttaken==-1)
        {
            return max(solve(nums,n-1,lasttaken,(greater),dp),1+solve(nums,n-1,n,greater,dp));
        }
        if(lasttaken!=-1 and dp[n-1][lasttaken-1][greater]!=-1)
        {
            return dp[n-1][lasttaken-1][greater];
        }
        if(lasttaken!=-1 and greater and nums[n-1]>nums[lasttaken-1])
        {
            ans = max({ans,1+solve(nums,n-1,n,(greater^1),dp),solve(nums,n-1,lasttaken,(greater),dp)});
        }
        if(lasttaken!=-1 and !greater and nums[n-1]<nums[lasttaken-1])
        {
            ans = max({ans,1+solve(nums,n-1,n,(greater^1),dp),solve(nums,n-1,lasttaken,(greater),dp)});
        }
        return dp[n-1][lasttaken-1][greater]=ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        return max(solve(nums,nums.size(),-1,1,dp),solve(nums,nums.size(),-1,0,dp));
    }
};