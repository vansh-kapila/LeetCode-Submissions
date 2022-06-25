class Solution {
public:
    const int mod = 1e9+7;
    int solve(int j,int n,int i,int last,vector<vector<vector<int>>> &dp)
    {
        if(j==n)
        {
            return 1;
        }
        if(last!=-1 and dp[j][i][last]!=-1)
        {
            return dp[j][i][last];
        }
        int store = 0;
        for(int k=1;k<=6;k++)
        {
            if(k!=i and __gcd(k,i)==1 and k!=last)
            {
                store = (store+solve(j+1,n,k,i,dp))%mod;
            }
        }
        return dp[j][i][last]=store;
    }
    int distinctSequences(int n) {
        
        int subs = 0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(7,vector<int>(7,-1))); 
        for(int i=1;i<=6;i++)
        {
            subs = (subs+solve(0,n-1,i,0,dp))%mod;
        }
        return subs;
    }
};