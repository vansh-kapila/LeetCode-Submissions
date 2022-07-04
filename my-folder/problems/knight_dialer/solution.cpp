class Solution {
public:
    const long long mod = 1e9+7;
    vector<vector<int>> moves = 
    {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {2,4},
    };
    int solve(int n,int i,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n-1][i]!=-1)
        {
            return dp[n-1][i];
        }
        long long ret = 0;
        for(auto j:moves[i])
        {
            ret = (ret + solve(n-1,j,dp))%mod;
        }
        return dp[n-1][i]=ret;
    }
    int knightDialer(int n) {
        long long ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(10,-1));
        for(int i=0;i<=9;i++)
        {
            ans = (ans + solve(n-1,i,dp))%mod;
        }
        return ans%mod;
    }
};