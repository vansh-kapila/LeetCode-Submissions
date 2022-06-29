class Solution
{
    public:
        int fib(int n,vector<int> &dp)
        {
            if (n == 0)
            {
                return 1;
            }
            if(dp[n]!=-1)
            {
                return dp[n];
            }
            int ans = 0;
            if (n >= 2)
            {
                ans = ans + fib(n - 1,dp) + fib(n - 2,dp);
            }
            else
            {
                ans = ans + fib(n - 1,dp);
            }
            return dp[n]=ans;
        }
    int climbStairs(int n)
    {
        vector<int> dp(n+1,-1);
        return fib(n,dp);
    }
};