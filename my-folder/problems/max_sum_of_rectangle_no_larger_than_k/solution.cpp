class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }  
        int ans = INT_MIN;
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
                
                set<int> ms;
                ms.insert(0);
                int sum = 0;
                for(auto i:v)
                {              
                    sum+=i;
                    auto it = ms.lower_bound(sum-target);
                    if(it!=ms.end())
                    {
                        ans = max(ans,sum-*it);
                    }
                    ms.insert(sum);
                }
            } 
        }
        return ans;
    }
};