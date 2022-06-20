class Solution
{
    public:

        vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
        {
            vector<vector < int>> dp(mat.size(), vector<int> (mat[0].size(), 1e9+7));

            for (int i = 0; i < mat.size(); i++)
            {
                for (int j = 0; j < mat[0].size(); j++)
                {
                    if (mat[i][j] == 0)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        int leftmin=1e9, downmin=1e9;
                        if (j >= 1)
                        {
                            leftmin = dp[i][j - 1] + 1;
                        }
                        if (i >= 1)
                        {
                            downmin = dp[i - 1][j] + 1;
                        }
                        dp[i][j] = min({ dp[i][j],leftmin,downmin});
                    }
                }
            }
            
            for (int i = mat.size()-1; i>=0; i--)
            {
                for (int j = mat[0].size()-1; j >=0; j--)
                {
                    if (mat[i][j] == 0)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        int rightmin=1e9, upmin=1e9;
                        if (j<mat[0].size()-1)
                        {
                            rightmin = dp[i][j + 1] + 1;
                        }
                        if (i<mat.size()-1)
                        {
                            upmin = dp[i + 1][j] + 1;
                        }
                        dp[i][j] = min({ dp[i][j],upmin,rightmin});
                    }
                }
            }
            return dp;
        }
};