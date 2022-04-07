class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++)
        {   vector<int> store;
            int j = 0;
            int k = i;
            while(k<mat.size() and j<mat[0].size())
            {
                store.push_back(mat[k][j]);
                k++;j++;
            }
            sort(store.begin(),store.end());
            j = 0;
            k = i;
            int a = 0;
            while(k<mat.size() and j<mat[0].size())
            {
                mat[k][j] = store[a++];
                k++;j++;
            }
        }
        for(int i=1;i<mat[0].size();i++)
        {   vector<int> store;
            int j = 0;
            int k = i;
            while(k<mat[0].size() and j<mat.size())
            {
                store.push_back(mat[j][k]);
                k++;j++;
            }
            sort(store.begin(),store.end());
            j = 0;
            k = i;
            int a = 0;
            while(k<mat[0].size() and j<mat.size())
            {
                mat[j][k] = store[a++];
                k++;j++;
            }
        }
        return mat;
    }
};