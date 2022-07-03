class Solution
{
    public:
    long long mod = 1e9+7;
        long long solve(int i, string &s,vector<int> &dp)
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
            long long ans = 0;
            if (s[i] == '*')
            {
                ans = ans + 9* solve(i + 1, s, dp);
            }
            else
            {
                ans = ans + solve(i + 1, s, dp);
            }

            if (s[i] == '*'
                and i + 1 < s.length())
            {
                if (s[i + 1] == '*')
                {
                    ans = ans + 15* solve(i + 2, s, dp);
                }
                else if (s[i + 1] <= '6')
                {
                    ans = ans + 2* solve(i + 2, s, dp);
                }
                else
                {
                    ans = ans + solve(i + 2, s, dp);
                }
            }
            else if (i + 1 < s.length() and s[i + 1] == '*')
            {
                if (s[i] == '1')
                {
                    ans = ans + 9* solve(i + 2, s, dp);
                }
                else if (s[i] == '2')
                {
                    ans = ans + 6* solve(i + 2, s, dp);
                }
            }
            else
            {
                if (i + 1 < s.length())
                {
                    string y;
                    y.push_back(s[i]);
                    y.push_back(s[i + 1]);
                    if (s[i] != '*'
                        and s[i + 1] != '*' and stoi(y) <= 26)
                    {
                        ans = ans + solve(i + 2, s, dp);
                    }
                }
            }
            return dp[i]=(ans)%mod;
        }
    int numDecodings(string s)
    {
        vector<int> dp(s.length() + 1, -1);
        return solve(0, s, dp);
    }
};