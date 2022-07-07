class Solution {
public:
    bool solve(string &s1,string &s2,string &s3,int m,int n,int x,vector<vector<int>> &dp)
    {
        if(m==0 and n==0 and x==0)
        {
            return 1;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        bool ans=0;
        if(x!=0 and m!=0 and s1[m-1]==s3[x-1])
        {
            ans = ans|solve(s1,s2,s3,m-1,n,x-1,dp);
        }
        if(x!=0 and n!=0 and s2[n-1]==s3[x-1])
        {
            ans = ans|solve(s1,s2,s3,m,n-1,x-1,dp);
        }
        return dp[m][n]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) { 
         vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
         return solve(s1,s2,s3,s1.length(),s2.length(),s3.length(),dp);
    }
};