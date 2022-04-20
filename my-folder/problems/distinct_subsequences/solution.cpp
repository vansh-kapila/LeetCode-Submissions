class Solution {
public:   
    int solve(string &s,string &t,int n,int m,vector<vector<int>> &dp)
    {   
        if(m==0)
        {
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        if(dp[n-1][m-1]!=-1)
        {
            return dp[n-1][m-1];
        }
        if(s[n-1]==t[m-1])
        {
            return dp[n-1][m-1]=solve(s,t,n-1,m-1,dp)+solve(s,t,n-1,m,dp);
        }
        return dp[n-1][m-1]=solve(s,t,n-1,m,dp);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1);
        for(int i=0;i<s.length()+1;i++)
        {
            for(int j=0;j<t.length()+1;j++)
            {
                dp[i].push_back(-1);
            }
        }
        return solve(s,t,s.length(),t.length(),dp); 
    }
};