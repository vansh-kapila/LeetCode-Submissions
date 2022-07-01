class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
         vector<vector<int>> mat(n,vector<int>(n,0));
         for(int i=0;i<dig.size();i++)
         {
             mat[dig[i][0]][dig[i][1]]++;
         }
        int ans = 0;
        for(auto i:artifacts)
        {
            int count = 0;
            for(int j=i[0];j<=i[2];j++)
            {
                for(int k=i[1];k<=i[3];k++)
                {
                    if(!mat[j][k])
                    {
                        count++;
                        break;
                    }
                }
            }
            if(!count)
            {
                ans++;
            }
        }
        return ans;
    }
};