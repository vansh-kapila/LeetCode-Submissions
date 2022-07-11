class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            set<int> st;
            for(int j=0;j<matrix[i].size();j++)
            {
                st.insert(matrix[i][j]);
            }
            if(st.size()!=matrix.size())
            {
                return 0;
            }
        }
        for(int i=0;i<matrix[0].size();i++)
        {
            set<int> st;
            for(int j=0;j<matrix.size();j++)
            {
                st.insert(matrix[j][i]);
            }
            if(st.size()!=matrix.size())
            {
                return 0;
            }
        }
        return 1;
    }
};