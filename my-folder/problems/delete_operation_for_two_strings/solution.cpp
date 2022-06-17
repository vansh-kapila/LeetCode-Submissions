class Solution
{
    public:
        int lcs(string &word1, string &word2, int m, int n, vector<vector < int>> &dp)
        {
            if (m == 0 or n == 0)
            {
                return 0;
            }
            if (dp[m - 1][n - 1] != -1)
            {
                return dp[m - 1][n - 1];
            }
            if (word1[m - 1] == word2[n - 1])
            {
                return dp[m - 1][n - 1] = 1 + lcs(word1, word2, m - 1, n - 1, dp);
            }
            return dp[m - 1][n - 1] = max(lcs(word1, word2, m - 1, n, dp), lcs(word1, word2, m, n - 1, dp));
        }
    int minDistance(string word1, string word2)
    {
        vector<vector < int>> dp(word1.length() + 1, vector<int> (word2.length() + 1, -1));
        return word1.length() + word2.length() - 2* lcs(word1, word2, word1.length(), word2.length(), dp);
    }
};