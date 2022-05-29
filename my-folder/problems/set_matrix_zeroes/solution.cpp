class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0=0,col0=0;
      
        //make first element of row and first element of column 0 for every element.
        //obs - a single 0 in 0th row will make entire row zero which can cause discrepancy. So keep a bool variable which tracks the presence of zero element in first row/column.
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0 and i>0 and j>0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
                if(matrix[i][j]==0 and i==0)
                {
                    row0=1;
                }
                if(matrix[i][j]==0 and j==0)
                {
                    col0=1;
                }
            }
        }
        //problematic case :- | 1 | 1 | 0 |
                        //    | 1 | 1 | 1 |....
        //would make elements of zeroth column zero as well. so take the case for i>0 and j>0 for now.
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(i>0 and j>0 and (matrix[i][0]==0 or matrix[0][j]==0))
                {
                    matrix[i][j]=0;
                } 
            }
        }
        //handle the case for i==0 and j==0
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(i==0 and row0)
                {
                    matrix[i][j]=0;
                } 
                if(j==0 and col0)
                {
                    matrix[i][j]=0;
                } 
            }
        }
    }
};