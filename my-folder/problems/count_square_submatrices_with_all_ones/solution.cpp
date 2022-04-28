class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {   
                if(i>=1 and j>=1 and matrix[i][j]!=0){
                matrix[i][j] = min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]})+1;}
                sum+=matrix[i][j];   
            }
        }
        return sum;
    }
};