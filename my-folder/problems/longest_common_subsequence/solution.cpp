class Solution {
public: 
    int dp[1000][1000];
    int solve(string &x,string &y,int i,int m,int j,int n)
    {
        if(i==m or j==n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(x[i]==y[j])
        {
            return dp[i][j]=1+solve(x,y,i+1,m,j+1,n);
        }
        else
        {
            return dp[i][j]=max(solve(x,y,i,m,j+1,n),solve(x,y,i+1,m,j,n));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        for(int i=0;i<text1.length();i++)
        {
            for(int j=0;j<text2.length();j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(text1,text2,0,text1.length(),0,text2.length());
    }
};