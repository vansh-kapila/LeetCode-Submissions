class Solution
{
    public:
        int solve(int i, string &s,vector<int> &dp)
        {
            if (i == s.length())
            {
                return 1;
            }
            if (s[i] == '0')
            {
                return 0;
            }
            if(dp[i]!=-1)
            {
                return dp[i];
            }
            int ans = 0;
            string x;
            x.push_back(s[i]);
            ans = ans + solve(i + 1, s,dp);
            if (i + 1 != s.length())
            {
                x.push_back(s[i + 1]);
                if (stoi(x) <= 26)
                {
                    ans = ans + solve(i + 2, s,dp);
                }
            }
            return dp[i]=ans;
        }
    int numDecodings(string s)
    {
        vector<int> dp(s.length()+1,-1);
        return solve(0, s,dp);
    }
};