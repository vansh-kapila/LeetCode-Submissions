class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k = 0;
        vector<vector<int>> ans;
        if(original.size()!=m*n)
        {
            return ans;
        }
        for(int i=0;i<m;i++)
        {
            vector<int> v;
            for(int j=0;j<n;j++)
            {
                v.push_back(original[k]);
                k++;
            }
            ans.push_back(v);
        }
        return ans;
    }
};