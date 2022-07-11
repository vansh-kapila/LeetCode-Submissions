class Solution {
public: 
    string shortestCommonSupersequence(string &str1, string &str2) {
       
        vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,0));
        for(int i=1;i<=str1.length();i++)
        {
            for(int j=1;j<=str2.length();j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        string lcs;
        int m = str1.length();
        int n = str2.length();
        
        while(m>=1 and n>=1)
        {
            if(str1[m-1]==str2[n-1])
            {
                m--;
                n--;
                lcs.push_back(str1[m]);
            }
            else if(dp[m-1][n]>dp[m][n-1])
            {
                m--;
            }
            else
            {
                n--;
            }
        }
        reverse(lcs.begin(),lcs.end());  
        string ans; 
        int i=0,j=0,c=0;
        while(i<str1.length() or j<str2.length())
        {
            while(i<str1.length() and str1[i]!=lcs[c])
            {
                ans.push_back(str1[i++]);
            }
            while(j<str2.length() and str2[j]!=lcs[c])
            {
                ans.push_back(str2[j++]);
            }
            if(c<lcs.length() and str1[i]==lcs[c] and str2[j]==lcs[c])
            {
                ans.push_back(lcs[c++]);
                i++;
                j++;
            }
        }
        return ans;
        
    }
};