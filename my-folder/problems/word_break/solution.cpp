class Solution
{
    public:
    set<string> ss;
    bool solve(string &s, int start,vector<int> &dp)
    {
        if (start == s.length())
        {
            return true;
        }
        if(dp[start]!=-1)
        {
            return dp[start];
        }
        string x;
        bool ans = 0;
        for (int i = start; i < s.length(); i++)
        {
            x.push_back(s[i]);
            if (ss.find(x) != ss.end())
            {
                ans = max(ans,solve(s, i + 1,dp));
            }
        }
        return dp[start]=max(dp[start],(int)ans);
    }
    bool wordBreak(string &s, vector<string> &wordDict)
    {
        for(auto &i:wordDict)
        {
            ss.insert(i);
        }
        vector<int> dp(s.length()+1,-1);
        return solve(s, 0,dp);
    }
};