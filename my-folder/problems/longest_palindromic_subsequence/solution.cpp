class Solution {
public:
    int lcs(string &x,string &s,int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 or j==0)
        {
            return 0;
        }
        if(dp[i-1][j-1]!=-1)
        {
            return dp[i-1][j-1];
        }
        int ans = 0;
        if(x[i-1]==s[j-1])
        {
            return dp[i-1][j-1]=1+lcs(x,s,i-1,j-1,dp);
        }
        ans = max({ans,lcs(x,s,i-1,j,dp),lcs(x,s,i,j-1,dp)});
        return dp[i-1][j-1]=ans;
    }
    int longestPalindromeSubseq(string s) {
        string x = s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(x.length()+1,vector<int>(x.length()+1,-1));
        return lcs(x,s,s.length(),x.length(),dp);
    }
};