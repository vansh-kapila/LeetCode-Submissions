class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        
        for(int i=0;i<matrix.size();i++)
        {  
            if(matrix[i][0]<=target and matrix[i][n-1]>=target){
            vector<int> v = matrix[i];
            
                for(int j=0;j<matrix[0].size();j++)
                {
                return binary_search(v.begin(),v.end(),target);
                }
        }}
        return false;
    }
};