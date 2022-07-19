class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int top = 0,bottom = matrix.size()-1,left = 0,right = matrix[0].size()-1;
        while(top<=bottom and left<=right)
        { 
            for(int i=left;i<=right;i++)
            {
                v.push_back(matrix[top][i]);
            }
            top++; 
            for(int i=top;i<=bottom;i++)
            {
                v.push_back(matrix[i][right]);
            }
            if(top<=bottom){
            right--;
            for(int i=right;i>=left;i--)
            {
                v.push_back(matrix[bottom][i]);
            }
            }
            if(left<=right){
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                v.push_back(matrix[i][left]);
            }
                left++;
            }
        }
        return v;
    }
};