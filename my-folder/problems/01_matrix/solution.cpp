class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),1e9));
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            ans++;
            int n = q.size();
            while(n--)
            {
                auto it = q.front();
                q.pop();
                if(it.first-1>=0 and mat[it.first-1][it.second]==1)
                {
                    mat[it.first-1][it.second]=2;
                    q.push({it.first-1,it.second});
                    dp[it.first-1][it.second]=min(dp[it.first-1][it.second],ans);
                }
                if(it.second-1>=0 and mat[it.first][it.second-1]==1)
                {
                    mat[it.first][it.second-1]=2;
                    q.push({it.first,it.second-1});
                    dp[it.first][it.second-1]=min(dp[it.first][it.second-1],ans);
                }
                 if(it.first+1<mat.size() and mat[it.first+1][it.second]==1)
                {
                    mat[it.first+1][it.second]=2;
                    q.push({it.first+1,it.second});
                    dp[it.first+1][it.second]=min(dp[it.first+1][it.second],ans);
                }
                if(it.second+1<mat[0].size() and mat[it.first][it.second+1]==1)
                {
                    mat[it.first][it.second+1]=2;
                    q.push({it.first,it.second+1});
                    dp[it.first][it.second+1]=min(dp[it.first][it.second+1],ans);
                }
            }
        }
        
//         for(int i=0;i<mat.size();i++)
//         {
//             for(int j=0;j<mat[0].size();j++)
//             {
//                 if(mat[i][j]==0)
//                 {
//                     q.push({i,j});
//                 }
//                 if(mat[i][j]==2)
//                 {
//                     mat[i][j]=1;
//                 }
//             }
//         }
        
//         ans = 0;
//         while(!q.empty())
//         {
//             ans++;
//             int n = q.size();
//             while(n--)
//             {
//                 auto it = q.front();
//                 q.pop();
//                 if(it.first+1<mat.size() and mat[it.first+1][it.second]==1)
//                 {
//                     mat[it.first+1][it.second]=2;
//                     q.push({it.first+1,it.second});
//                     if(dp[it.first+1][it.second]!=0)
//                     {
//                         dp[it.first+1][it.second]=min(dp[it.first+1][it.second],ans);
//                     }
//                     else
//                     {
//                         dp[it.first+1][it.second] = ans;
//                     }
//                 }
//                 if(it.second+1<mat[0].size() and mat[it.first][it.second+1]==1)
//                 {
//                     mat[it.first][it.second+1]=2;
//                     q.push({it.first,it.second+1}); 
//                     if(dp[it.first][it.second+1]!=0)
//                     {
//                         dp[it.first][it.second+1]=min(dp[it.first][it.second+1],ans);
//                     }
//                     else
//                     {
//                         dp[it.first][it.second+1] = ans;
//                     }
//                 }
//             }
//         }
        return dp;
    }
};