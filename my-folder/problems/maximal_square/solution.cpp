class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[matrix.size()][matrix[0].size()];
        int ans= 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0' or !i or !j)
                {
                    dp[i][j] = matrix[i][j]-'0';
                }
                else
                {
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};