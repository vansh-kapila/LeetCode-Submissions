class Solution {
public:
    int solve(string &a,string &b,int m,int n,vector<vector<int>> &dp)
    { 
         if(m==0)
         {
             return n;
         }
         if(n==0)
         {
             return m;
         }
         if(dp[m-1][n-1]!=-1)
         {
             return dp[m-1][n-1];
         }
         if(a[m-1]==b[n-1])
         {
             return dp[m-1][n-1]=solve(a,b,m-1,n-1,dp);
         }
         return dp[m-1][n-1]=1+min({solve(a,b,m-1,n-1,dp),solve(a,b,m-1,n,dp),solve(a,b,m,n-1,dp)});
    }
    int minDistance(string word1, string word2) {
        if(word1.empty())
        {
            return word2.length();
        }
        if(word2.empty())
        {
            return word1.length();
        }
        vector<vector<int>> dp(word1.length(),vector<int> (word2.length(),-1));
        return solve(word1,word2,word1.length(),word2.length(),dp);
    }
};