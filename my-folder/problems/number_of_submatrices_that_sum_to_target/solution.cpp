class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) { 
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        } 
        map<int,int> mp;
        int ans = 0;
        for(int i=0;i<matrix[0].size();i++)
        {
            for(int j=i;j<matrix[0].size();j++)
            {
                vector<int> v;
                for(int k=0;k<matrix.size();k++)
                {
                    int x = i>=1?matrix[k][j]-matrix[k][i-1]:matrix[k][j];
                    v.push_back(x);
                }
                // for(auto i:v)
                // {
                //     cout<<i<<' ';
                // }
                // cout<<endl;
                mp[0]++;
                int sum = 0;
                for(auto i:v)
                {
                    sum = sum + i;
                    ans = ans + mp[sum-target];
                    mp[sum]++;
                }
                mp.clear();
            }
        }
        return ans;
    }
};